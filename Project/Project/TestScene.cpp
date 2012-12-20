//
//  TestScene.cpp
//  Project
//
//  Created by Colden Prime on 12/10/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "TestScene.h"
#include "MinerMan.h"
#include "MoveToAction.h"
#include "ScaleToAction.h"
#include "SpawnAction.h"
#include "RotateToAction.h"
#include "SequenceAction.h"
#include "CallFuncAction.h"
#include <math.h>

#define TurnIncrement 5
#define MoveIncrement 1

Point forward(Point start, float angle) {
    float x = cos(angle * (M_PI / 180));
    float z = sin(angle * (M_PI / 180));
    
    Point ret = PointAdd(PointMake(MoveIncrement * x, 0, MoveIncrement * z), start);
    
    return ret;
}


TestScene::TestScene() : Scene() {
    this->grid = new GridXZ();
    this->grid->set_anchorPoint(PointMake(0, 0, 0));
    this->addChild(this->grid);
    
    this->minerMan = new MinerMan();
    this->minerMan->set_position(PointMake(0, 0, 0));
    this->minerMan->set_anchorPoint(PointMake(.5, 0, .5));
    this->addChild(this->minerMan);
    
    KeyboardHandler::Instance()->AddListener(this, 'w');
    KeyboardHandler::Instance()->AddListener(this, 'a');
    KeyboardHandler::Instance()->AddListener(this, 's');
    KeyboardHandler::Instance()->AddListener(this, 'd');
    
    manPosition = PointMake(0, 0, 0);
    manRotation = 0;
}

void TestScene::onEnter() {
    this->minerMan->set_position(PointMake(0, 0, 0));
    this->minerMan->set_scale(1);
    
}

void TestScene::KeyPressed(void* handler, char key, bool down) {
    if(down) {
        switch (key) {
            case 'w': //fowards
                manPosition = forward(manPosition, -manRotation);
                this->makeStep();
                break;
            case 'a': //turn left
                manRotation += 5;
                this->makeStep();
                break;
            case 's': // backwards
                manPosition = forward(manPosition, 180 - manRotation);
                this->makeStep();
                break;
            case 'd': //turn right
                manRotation -= 5;
                this->makeStep();
                break;
            default:
                break;
        }
    }
    else {
        
    }
}

void TestScene::makeStep() {
    this->minerMan->startWalkAnimation();
    
    printf("position: (%f, %f, %f)\n", manPosition.x, manPosition.y, manPosition.z);
    printf("rotation: %f\n", manRotation);
    
    float x = -((manPosition.x * cos(manRotation * (M_PI / 180))) - (manPosition.z * sin(manRotation * (M_PI / 180))));
    float y = 0;
    float z = -((manPosition.x * sin(manRotation * (M_PI / 180))) + (manPosition.z * cos(manRotation * (M_PI / 180))));
    
    this->grid->set_position(PointMake(x, y, z));
    this->grid->set_angleY(-manRotation);
}
