//
//  MoveToAction.cpp
//  Project
//
//  Created by Colden Prime on 12/9/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "MoveToAction.h"
#include "Node.h"

MoveToAction::MoveToAction(float duration, Point destination) : Action(duration) {
    this->destination = destination;
}

void MoveToAction::startWithTarget(Node *node) {
    Action::startWithTarget(node);
    
    this->origin = node->get_position();
    
    this->delta = PointSub(this->destination, this->origin);
}
void MoveToAction::finish() {
    Action::finish();
    this->get_target()->set_position(this->destination);
}

void MoveToAction::update(float t) {
    Action::update(t);
    
    Point newPosition = PointAdd(this->origin, PointMake(this->delta.x * t, this->delta.y * t, this->delta.z * t));
    
    this->get_target()->set_position(newPosition);
}