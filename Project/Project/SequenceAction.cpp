//
//  SequenceAction.cpp
//  Project
//
//  Created by Colden Prime on 12/11/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "SequenceAction.h"

SequenceAction::SequenceAction(std::vector<Action *> *actions) : Action(0) {
    this->actions = actions;
    
    float runningDuration = 0;
    
    std::vector<Action *>::iterator actionIt = actions->begin();
    for(; actionIt != actions->end(); ++actionIt) {
        Action *action = *actionIt;
        
        runningDuration += action->duration;
    }
    
    this->duration = runningDuration;
}

void SequenceAction::startWithTarget(Node *node) {
    Action::startWithTarget(node);
    this->current = 0;
    this->finishedElapsed = 0;
    this->currentStarted = false;
}

void SequenceAction::update(float t) {
    if(!this->actions->empty()) {

        for( ; this->current != this->actions->size(); ) {
            Action *action = this->actions->at(this->current);
            if(!this->currentStarted) {
                action->startWithTarget(this->target);
                this->currentStarted = true;
            }
            
            float offsetT = (this->elapsed - this->finishedElapsed) / (this->duration - this->finishedElapsed);
            float scaledT = (offsetT / (action->duration / (this->duration - this->finishedElapsed)));
            float fixedT = MAX(MIN(scaledT, 1), 0);
            action->update(fixedT);
            
            if(action->isFinished) {
                action->finish();
                this->finishedElapsed += action->duration;
                this->current++;
                this->currentStarted = false;
                continue;
            } else {
                break;
            }
        }
    }
}