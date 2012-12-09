//
//  Action.cpp
//  Project
//
//  Created by Colden Prime on 12/6/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "Action.h"
#import <iostream>
#import "Node.h"

#define MIN(A,B) ((A < B) ? A : B)

Action::Action(float duration) {
    this->duration = duration;
}

void Action::startWithTarget(Node *node) {
    this->target = node;
}
bool Action::isDone() {
    return this->elapsed >= this->duration;
}

void Action::tick(float dt) {
    std::cout << "Delta time: " << dt << std::endl;
    
    this->elapsed += dt;
    
    this->update(MIN(this->elapsed / this->duration, 1));
}

void Action::update(float t) {
    //override this method
}