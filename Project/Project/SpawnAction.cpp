//
//  SpawnAction.cpp
//  Project
//
//  Created by Colden Prime on 12/12/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "SpawnAction.h"

float maxDuration(std::vector<Action *> *actions) {
    float longest = 0;
    
    std::vector<Action *>::iterator actionIt = actions->begin();
    for(; actionIt != actions->end(); ++actionIt) {
        Action *action = *actionIt;
        
        if(longest < action->get_duration()) {
            longest = action->get_duration();
        }
    }
    
    return longest;
}

SpawnAction::SpawnAction(std::vector<Action *> *actions) : Action(maxDuration(actions)) {
    this->actions = actions;
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
    Action::update(t);
    
    std::vector<Action *>::iterator actionIt = actions->begin();
    for( ; actionIt != actions->end(); ++actionIt) {
        Action *action = *actionIt;
        
        if(!action->isFinished()) {
            float localT = MIN(MAX((this->get_duration() * t) / action->get_duration(), 0), 1);
            action->update(localT);
        }
    }
}