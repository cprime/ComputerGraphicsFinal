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

#pragma mark - constructors

Action::Action() {
    _duration = __FLT_EPSILON__;
    _finished = false;
}

Action::Action(float duration) {
    _duration = duration;
    _finished = false;
}

#pragma mark - accessor methods

int Action::get_tag() {
    return _tag;
}
float Action::get_duration() {
    return _duration;
}
float Action::get_elapsed() {
    return _elapsed;
}
Node *Action::get_target() {
    return _target;
}
bool Action::isFinished() {
    return _finished;
}

#pragma mark - running methods

void Action::startWithTarget(Node *node) {
    _target = node;
    _elapsed = 0;
    _finished = false;
}

void Action::step(float dt) {
    _elapsed += dt;
    float t = MIN(MAX(_elapsed / _duration, 0), 1);
    
    this->update(t);
}

void Action::update(float t) {
    if(t >= 1)
        _finished = true;
    
    //override this method and call it
}

void Action::finish() {
    _finished = true;
    
    //override this method
}

