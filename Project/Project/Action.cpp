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
#define MAX(A,B) ((A > B) ? A : B)

Action::Action(float duration) {
    this->duration = duration;
    this->isFinished = false;
}

void Action::startWithTarget(Node *node) {
    this->target = node;
}
bool Action::isDone() {
    return this->elapsed >= this->duration || this->isFinished;
}

void Action::tick(float dt) {
    this->elapsed += dt;
    float t = MIN(MAX(this->elapsed / this->duration, 0), 1);
    
//    std::cout << "Delta time: " << dt << std::endl;
//    std::cout << "Total time: " << this->elapsed << std::endl;
//    std::cout << "T: " << t << std::endl;
    
    this->update(t);
}

void Action::update(float t) {
    if(t >= 1)
        this->isFinished = true;
    //override this method
}