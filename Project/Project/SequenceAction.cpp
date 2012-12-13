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
    
    if(!this->actions->empty()) {
        std::vector<Action *>::iterator actionIt = actions->begin();
        for(; actionIt != actions->end(); ++actionIt) {
            Action *action = *actionIt;
            action->startWithTarget(node);
        }
    }
}

void SequenceAction::update(float t) {
    if(!this->actions->empty()) {

        for( ; this->current != this->actions->size(); ) {
            Action *action = this->actions->at(this->current);
            
            float offsetT = MIN(MAX((this->elapsed - this->finishedElapsed) / (this->duration - this->finishedElapsed), 0), 1);
            float scaledT = MIN(MAX((offsetT / (action->duration / this->duration)), 0), 1);
//            printf("%f , %f\n", offsetT, scaledT);
            action->update(scaledT);
            
            if(action->isFinished) {
                printf("next\n");
                this->finishedElapsed += action->duration;
                this->current++;
                continue;
            } else {
                break;
            }
        }
    }
}