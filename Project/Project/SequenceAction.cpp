//
//  SequenceAction.cpp
//  Project
//
//  Created by Colden Prime on 12/11/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "SequenceAction.h"

float combinedDuration(std::vector<Action *> *actions) {
    float runningDuration = 0;
    
    std::vector<Action *>::iterator actionIt = actions->begin();
    for(; actionIt != actions->end(); ++actionIt) {
        Action *action = *actionIt;
        
        runningDuration += action->get_duration();
    }
    
    return runningDuration;
}

SequenceAction::SequenceAction(std::vector<Action *> *actions) : Action(combinedDuration(actions)) {
    this->actions = actions;
}

void SequenceAction::startWithTarget(Node *node) {
    Action::startWithTarget(node);
    this->current = 0;
    this->finishedElapsed = 0;
    this->currentStarted = false;
}

void SequenceAction::update(float t) {
    Action::update(t);
    
    if(!this->actions->empty()) {

        for( ; this->current != this->actions->size(); ) {
            Action *action = this->actions->at(this->current);
            if(!this->currentStarted) {
                action->startWithTarget(this->get_target());
                this->currentStarted = true;
            }
            
            float offsetT = (this->get_elapsed() - this->finishedElapsed) / (this->get_duration() - this->finishedElapsed);
            float scaledT = (offsetT / (action->get_duration() / (this->get_duration() - this->finishedElapsed)));
            float fixedT = MAX(MIN(scaledT, 1), 0);
            action->update(fixedT);
            
            if(action->isFinished()) {
                action->finish();
                this->finishedElapsed += action->get_duration();
                this->current++;
                this->currentStarted = false;
            
                continue;
            } else {
                break;
            }
        }
    }
}

