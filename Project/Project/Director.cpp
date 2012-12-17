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
#import <sys/time.h>
#import "ActionManager.h"

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

void Director::calculateDeltaTime()
{
	struct timeval now;
    if( gettimeofday( &now, NULL) != 0 ) {
		dt = 0;
		return;
	}
    
    static clock_t total = 0;
    if(this->isFirstTick) {
        this->dt = 0;
        this->isFirstTick = false;
    } else {
        // new delta time
        float delta = (now.tv_sec - this->lastUpdate.tv_sec) + (now.tv_usec - this->lastUpdate.tv_usec) / 1000000.0f;
        if(delta < 0) {
            this->dt = 0;
        } else {
            this->dt = delta;
        }
        total += this->dt;
    }
    
    if( dt > 0.2f )
		dt = 1/60.0f;
    
    this->lastUpdate = now;
}

Director::Director()
{
    this->runningScene = new Scene();
    
    this->isFirstTick = true;
    
    KeyboardHandler::Instance()->AddListener(this, 'z');
    KeyboardHandler::Instance()->AddListener(this, 'x');
    KeyboardHandler::Instance()->AddListener(this, 'c');
    KeyboardHandler::Instance()->AddListener(this, 'Z');
    KeyboardHandler::Instance()->AddListener(this, 'X');
    KeyboardHandler::Instance()->AddListener(this, 'C');
    KeyboardHandler::Instance()->AddListener(this, (char)27);
}

void Director::runScene(Scene *scene) {
    this->runningScene = scene;
    
    this->runningScene->onEnter();
}

void Director::update() {
    this->calculateDeltaTime();
    
    ActionManager::SharedManager()->update(this->dt);
    
    glPushMatrix();
    
    this->runningScene->visit();
    
    glPopMatrix();
}

void Director::KeyPressed(void* handler, char key, bool down) {
    if(down) {
        switch (key) {
            case 'z':
                glRotatef(15.,1.0,0.0,0.0);
                break;
            case 'x':
                glRotatef(15.,0.0,1.0,0.0);
                break;
            case 'c':
                glRotatef(15.,0.0,0.0,1.0);
                break;
            case 'Z':
                glRotatef(-15.,1.0,0.0,0.0);
                break;
            case 'X':
                glRotatef(-15.,0.0,1.0,0.0);
                break;
            case 'C':
                glRotatef(-15.,0.0,0.0,1.0);
                break;
            case 27:
                exit(0);
                break;
        }
    }
}