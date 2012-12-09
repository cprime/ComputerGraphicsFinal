//
//  MoveToAction.cpp
//  Project
//
//  Created by Colden Prime on 12/9/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "MoveToAction.h"
#import "Node.h"

MoveToAction::MoveToAction(float duration, Point destination) : Action(duration) {
    this->destination = destination;
}

void MoveToAction::startWithTarget(Node *node) {
    Action::startWithTarget(node);
    
    this->origin = node->get_position();
    
    this->delta = PointSub(this->destination, this->origin);
}

void MoveToAction::update(float t) {
    Point newPosition = PointAdd(this->origin, PointMake(this->delta.x * t, this->delta.y * t, this->delta.z * t));
    this->target->set_position(newPosition);
}