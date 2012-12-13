//
//  SpawnAction.cpp
//  Project
//
//  Created by Colden Prime on 12/12/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "SpawnAction.h"

SpawnAction::SpawnAction(std::vector<Action *> *actions) : Action(0) {
    this->actions = actions;
    
    float longest = 0;
    
    std::vector<Action *>::iterator actionIt = actions->begin();
    for(; actionIt != actions->end(); ++actionIt) {
        Action *action = *actionIt;
        
        if(longest < action->duration) {
            longest = action->duration;
        }
    }
    
    this->duration = longest;
}

void SpawnAction::startWithTarget(Node *node) {
    Action::startWithTarget(node);
    
    std::vector<Action *>::iterator actionIt = actions->begin();
    for( ; actionIt != actions->end(); ++actionIt) {
        Action *action = *actionIt;
        
        action->startWithTarget(node);
    }
}

void SpawnAction::update(float t) {
    std::vector<Action *>::iterator actionIt = actions->begin();
    for( ; actionIt != actions->end(); ++actionIt) {
        Action *action = *actionIt;
        
        if(!action->isFinished) {
            float localT = MIN(MAX((this->duration * t) / action->duration, 0), 1);
            action->update(localT);
        }
    }
}