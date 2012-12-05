//
//  Director.cpp
//  Project
//
//  Created by Colden Prime on 12/4/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "Director.h"
#import <GLUT/GLUT.h>
#import <time.h>

Director * Director::m_pInstance = NULL;

Director * Director::SharedDirector()
{
    if (!m_pInstance)
        m_pInstance = new Director;
    
    return m_pInstance;
}

Director::Director(Director const & other)
{
}

Director & Director::operator= (const Director & other)
{
    return *this;
}

KeyboardHandler * Director::get_keyboardHandler() {
    return this->keyboardHandler;
}

void Director::calculateDeltaTime()
{
	clock_t now;
    now = clock();
	
	// new delta time
    this->dt = (now - this->lastUpdate) / CLOCKS_PER_SEC;
    if(this->dt < 0) this->dt = 0;
    
    this->lastUpdate = now;
}

Director::Director()
{
    this->keyboardHandler = new KeyboardHandler();
    
    this->rootNode = new Node();
    
//    Node *testObject = new Node();
//    this->rootNode->addChild(testObject);
//    
//    Node *child1 = new Node();
//    child1->set_position(PointMake(5, 5, 0));
//    child1->set_scale(.5);
//    testObject->addChild(child1);
}

void Director::update() {
    this->calculateDeltaTime();
    
    //Tick Actions
    
    glPushMatrix();
    
    this->rootNode->visit();
    
    glPopMatrix();
}