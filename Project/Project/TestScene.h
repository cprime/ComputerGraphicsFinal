//
//  TestScene.h
//  Project
//
//  Created by Colden Prime on 12/10/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__TestScene__
#define __Project__TestScene__

#include "Scene.h"
#include "KeyboardHandler.h"
#include "GridXZ.h"

class MinerMan;

class TestScene : public Scene, public KeyboardListener {
    GridXZ *grid;
    MinerMan *minerMan;
    
    Point manPosition;
    float manRotation;
    
    void makeStep();
public:
    TestScene();
    void onEnter();
    
    void KeyPressed(void* handler, char key, bool down);
};

#endif /* defined(__Project__TestScene__) */
