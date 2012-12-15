//
//  TestScene.cpp
//  Project
//
//  Created by Colden Prime on 12/10/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "TestScene.h"
#import "VectorMan.h"
#import "MoveToAction.h"
#import "ScaleToAction.h"
#import "SpawnAction.h"
#import "RotateToAction.h"
#import "SequenceAction.h"
#import "CallFuncAction.h"

void halfWay() {
    printf("HALF WAY!!!\n");
}

void finished() {
    printf("FINIHSED!!!\n");
}

TestScene::TestScene() : Scene() {
    this->vectorMan = new VectorMan();
    this->vectorMan->set_position(PointMake(0, 0, 0));
//    this->vectorMan->set_angleX(30.0);
//    this->vectorMan->set_angleY(45.0);
//    this->vectorMan->set_angleZ(-30.0);
    this->addChild(this->vectorMan);
}

void TestScene::onEnter() {
    this->vectorMan->set_position(PointMake(0, 0, 0));
    this->vectorMan->set_scale(1);
    
    std::vector<Action *> *actions = new std::vector<Action *>;
    
    MoveToAction *moveToAction = new MoveToAction::MoveToAction(2, PointMake(5, 0, 0));
    actions->push_back(moveToAction);
    
    ScaleToAction *scaleToAction = new ScaleToAction::ScaleToAction(2.0, 3);
    actions->push_back(scaleToAction);
    
    CallFuncAction *callFunc = new CallFuncAction::CallFuncAction(&halfWay);
    actions->push_back(callFunc);
    
    moveToAction = new MoveToAction::MoveToAction(2, PointMake(0, 0, 0));
    actions->push_back(moveToAction);
    
    scaleToAction = new ScaleToAction::ScaleToAction(2.0, 1);
    actions->push_back(scaleToAction);
    
    callFunc = new CallFuncAction::CallFuncAction(&finished);
    actions->push_back(callFunc);
    
    RotateToAction *rotateAction = new RotateToAction(2.0, 30.0, 30.0, 0.0);
    actions->push_back(rotateAction);

    rotateAction = new RotateToAction(2.0, 0.0, 0.0, 0.0);
    actions->push_back(rotateAction);
    
//    SpawnAction *spawnAction = new SpawnAction::SpawnAction(actions);
//    this->vectorMan->runAction(spawnAction);
    
    SequenceAction *sequenceAction = new SequenceAction::SequenceAction(actions);
    this->vectorMan->runAction(sequenceAction);
    
}