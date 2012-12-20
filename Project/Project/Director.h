//
//  Director.h
//  Project
//
//  Created by Colden Prime on 12/4/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__Director__
#define __Project__Director__

#include <vector>
#include "time.h"
#include <sys/time.h>
#include "KeyboardHandler.h"
#include "Scene.h"

class Director : public KeyboardListener {
public:
    static Director *SharedDirector();
    
    void runScene(Scene *scene);
    void update();
    
    void KeyPressed(void* handler, char key, bool down);
private:
    Scene *runningScene;
    
    bool isFirstTick;
    float dt;
    struct timeval lastUpdate;
    
    Director();
    Director(Director const&);             // copy constructor is private
    Director& operator=(Director const&);  // assignment operator is private
    static Director* m_pInstance;
    
    void calculateDeltaTime();
};

#endif /* defined(__Project__Director__) */
