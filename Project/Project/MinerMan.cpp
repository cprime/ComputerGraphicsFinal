//
//  MinerMan.cpp
//  Project
//
//  Created by Colden Prime on 12/10/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "MinerMan.h"
#import "RotateToAction.h"
#import "SequenceAction.h"
#import "RepeatAction.h"

MinerMan::MinerMan() : Node() {
    
    this->head = new NodeCube();
    this->head->set_color(ColorMake(1.0, 1.0, 1.0));
    this->head->set_scaleX(4);
    this->head->set_scaleY(3);
    this->head->set_scaleZ(4);
    this->head->set_position(PointMake(0, 11.5, 0));
    this->head->set_anchorPoint(PointMake(.5, .5, .5));
    this->addChild(this->head);

    this->torso = new NodeCube();
    this->torso->set_color(ColorMake(1.0, 0.0, 1.0));
    this->torso->set_scaleX(2);
    this->torso->set_scaleY(5);
    this->torso->set_scaleZ(4);
    this->torso->set_position(PointMake(0, 7.5, 0));
    this->torso->set_anchorPoint(PointMake(.5, .5, .5));
    this->addChild(this->torso);
    
    this->leftArm = new MinerArm();
    this->leftArm->set_position(PointMake(0, 9, 3.0));
    this->leftArm->set_anchorPoint(PointMake(0.5, .833, 0.5));
    this->addChild(this->leftArm);
    
    this->rightArm = new MinerArm();
    this->rightArm->set_position(PointMake(0, 9, -3.0));
    this->rightArm->set_anchorPoint(PointMake(0.5, .833, 0.5));
    this->addChild(this->rightArm);
    
    this->leftLeg = new MinerLeg();
    this->leftLeg->set_position(PointMake(0, 5, 1.0));
    this->leftLeg->set_anchorPoint(PointMake(0.5, 1.0, 0.5));
    this->addChild(this->leftLeg);
    
    this->rightLeg = new MinerLeg();
    this->rightLeg->set_position(PointMake(0, 5, -1.0));
    this->rightLeg->set_anchorPoint(PointMake(.5, 1.0, .5));
    this->addChild(this->rightLeg);
    
    this->set_anchorPoint(PointMake(0, 0.5, 0.5));
    this->set_contentSize(SizeMake(12, 12, 12));
}

void MinerMan::draw() {
    Node::draw();
}

void MinerMan::startWalkAnimation() {
    std::vector<Action *> *actions;
    RotateToAction *rotateAction;
    SequenceAction *sequenceAction;
    RepeatAction *repeatAction;
    
    float legSpeed = .75;
    
    actions = new std::vector<Action *>;

    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, 30.0);
    actions->push_back(rotateAction);

    rotateAction = new RotateToAction(legSpeed, 0.0, 0.0, -30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, 0.0);
    actions->push_back(rotateAction);

    sequenceAction = new SequenceAction::SequenceAction(actions);
    repeatAction = new RepeatAction::RepeatAction(sequenceAction, 0);
    this->leftLeg->runAction(repeatAction);
    
    actions = new std::vector<Action *>;
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, -30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed, 0.0, 0.0, 30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, 0.0);
    actions->push_back(rotateAction);
    
    sequenceAction = new SequenceAction::SequenceAction(actions);
    repeatAction = new RepeatAction::RepeatAction(sequenceAction, 0);
    this->rightLeg->runAction(repeatAction);
    
    //arms
    actions = new std::vector<Action *>;
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, 30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed, 0.0, 0.0, -30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, 0.0);
    actions->push_back(rotateAction);
    
    sequenceAction = new SequenceAction::SequenceAction(actions);
    repeatAction = new RepeatAction::RepeatAction(sequenceAction, 0);
    this->rightArm->runAction(repeatAction);
    
    actions = new std::vector<Action *>;
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, -30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed, 0.0, 0.0, 30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, 0.0);
    actions->push_back(rotateAction);
    
    sequenceAction = new SequenceAction::SequenceAction(actions);
    repeatAction = new RepeatAction::RepeatAction(sequenceAction, 0);
    this->leftArm->runAction(repeatAction);
}



