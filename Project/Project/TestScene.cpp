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
    this->vectorMan->startWalkAnimation();
    
}