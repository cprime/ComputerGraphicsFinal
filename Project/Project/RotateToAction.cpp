//
//  RotateToAction.cpp
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "RotateToAction.h"
#include "Node.h"

RotateToAction::RotateToAction(float duration, float destinationX, float destinationY, float destinationZ) : Action(duration) {
    this->destinationX = destinationX;
    this->destinationY = destinationY;
    this->destinationZ = destinationZ;
}

void RotateToAction::startWithTarget(Node *node) {
    Action::startWithTarget(node);
    
    this->originX = node->get_angleX();
    this->originY = node->get_angleY();
    this->originZ = node->get_angleZ();
    
    this->deltaX = this->destinationX - this->originX;
    this->deltaY = this->destinationY - this->originY;
    this->deltaZ = this->destinationZ - this->originZ;
}
void RotateToAction::finish() {
    Action::finish();
    this->get_target()->set_angleX(this->destinationX);
    this->get_target()->set_angleY(this->destinationY);
    this->get_target()->set_angleZ(this->destinationZ);
}

void RotateToAction::update(float t) {
    Action::update(t);
    
    this->get_target()->set_angleX(this->originX + (this->deltaX * t));
    this->get_target()->set_angleY(this->originY + (this->deltaY * t));
    this->get_target()->set_angleZ(this->originZ + (this->deltaZ * t));
}