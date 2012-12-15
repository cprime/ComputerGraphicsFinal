//
//  VectorMan.cpp
//  Project
//
//  Created by Colden Prime on 12/10/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "VectorMan.h"
#import "RotateToAction.h"
#import "SequenceAction.h"

VectorMan::VectorMan() : Node() {
    
    this->head = new NodeCube();
    this->head->set_color(ColorMake(1.0, 1.0, 0.0));
    this->head->set_scaleX(4);
    this->head->set_scaleY(3);
    this->head->set_scaleZ(4);
    this->head->set_position(PointMake(0, 2.5, 0));
    this->addChild(this->head);
    
    this->torso = new NodeCube();
    this->torso->set_color(ColorMake(1.0, 0.0, 1.0));
    this->torso->set_scaleX(2);
    this->torso->set_scaleY(5);
    this->torso->set_scaleZ(4);
    this->torso->set_position(PointMake(0, -1.5, 0));
    this->addChild(this->torso);
    
    this->leftArm = new NodeCube();
    this->leftArm->set_color(ColorMake(0.0, 1.0, 0.0));
    this->leftArm->set_scaleX(2);
    this->leftArm->set_scaleY(6);
    this->leftArm->set_scaleZ(2);
    this->leftArm->set_position(PointMake(0, -2.0, 3.0));
    this->addChild(this->leftArm);
    
    this->rightArm = new NodeCube();
    this->rightArm->set_color(ColorMake(1.0, 0.0, 0.0));
    this->rightArm->set_scaleX(2);
    this->rightArm->set_scaleY(6);
    this->rightArm->set_scaleZ(2);
    this->rightArm->set_position(PointMake(0, -2.0, -3.0));
    this->addChild(this->rightArm);
    
    this->leftLeg = new NodeCube();
    this->leftLeg->set_color(ColorMake(0.0, 1.0, 1.0));
    this->leftLeg->set_scaleX(2);
    this->leftLeg->set_scaleY(5);
    this->leftLeg->set_scaleZ(2);
    this->leftLeg->set_position(PointMake(0, -6.5, 1.0));
    this->addChild(this->leftLeg);
    
    this->rightLeg = new NodeCube();
    this->rightLeg->set_color(ColorMake(0.0, 0.0, 1.0));
    this->rightLeg->set_scaleX(2);
    this->rightLeg->set_scaleY(5);
    this->rightLeg->set_scaleZ(2);
    this->rightLeg->set_position(PointMake(0, -6.5, -1.0));
    this->addChild(this->rightLeg);
}

void VectorMan::draw() {
    Node::draw();
}

void VectorMan::startWalkAnimation() {
    std::vector<Action *> *actions = new std::vector<Action *>;

    RotateToAction *rotateAction = new RotateToAction(1.0, 0.0, 0.0, 30.0);
    actions->push_back(rotateAction);

    rotateAction = new RotateToAction(2.0, 0.0, 0.0, -30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(2.0, 0.0, 0.0, 30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(1.0, 0.0, 0.0, 0.0);
    actions->push_back(rotateAction);

    SequenceAction *sequenceAction = new SequenceAction::SequenceAction(actions);
    this->leftLeg->runAction(sequenceAction);
    
    actions = new std::vector<Action *>;
    
    rotateAction = new RotateToAction(1.0, 0.0, 0.0, -30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(2.0, 0.0, 0.0, 30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(2.0, 0.0, 0.0, -30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(1.0, 0.0, 0.0, 0.0);
    actions->push_back(rotateAction);
    
    sequenceAction = new SequenceAction::SequenceAction(actions);
    this->rightLeg->runAction(sequenceAction);
}



