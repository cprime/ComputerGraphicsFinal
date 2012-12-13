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
#import "SequenceAction.h"

TestScene::TestScene() : Scene() {
    this->vectorMan = new VectorMan();
    this->vectorMan->set_position(PointMake(0, 0, 0));
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
    
    moveToAction = new MoveToAction::MoveToAction(2, PointMake(0, 0, 0));
    actions->push_back(moveToAction);
    
    scaleToAction = new ScaleToAction::ScaleToAction(2.0, 1);
    actions->push_back(scaleToAction);
    
//    SpawnAction *spawnAction = new SpawnAction::SpawnAction(actions);
//    this->vectorMan->runAction(spawnAction);
    
    SequenceAction *sequenceAction = new SequenceAction::SequenceAction(actions);
    this->vectorMan->runAction(sequenceAction);
    
}