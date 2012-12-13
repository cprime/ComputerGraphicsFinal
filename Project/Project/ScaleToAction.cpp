//
//  ScaleToAction.cpp
//  Project
//
//  Created by Colden Prime on 12/9/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "ScaleToAction.h"
#import "Node.h"

ScaleToAction::ScaleToAction(float duration, float destination) : Action(duration) {
    this->destinationX = destination;
    this->destinationY = destination;
    this->destinationZ = destination;
}
ScaleToAction::ScaleToAction(float duration, float destinationX, float destinationY, float destinationZ) : Action(duration) {
    this->destinationX = destinationX;
    this->destinationY = destinationY;
    this->destinationZ = destinationZ;
}

void ScaleToAction::startWithTarget(Node *node) {
    Action::startWithTarget(node);
    
    this->originX = node->get_scaleX();
    this->originY = node->get_scaleY();
    this->originZ = node->get_scaleZ();
    
    this->deltaX = this->destinationX - this->originX;
    this->deltaY = this->destinationY - this->originY;
    this->deltaZ = this->destinationZ - this->originZ;
}

void ScaleToAction::update(float t) {
    Action::update(t);
    
    this->target->set_scaleX(this->originX + this->deltaX * t);
    this->target->set_scaleY(this->originY + this->deltaY * t);
    this->target->set_scaleZ(this->originZ + this->deltaZ * t);
    
//    printf("%f\n", t);
}