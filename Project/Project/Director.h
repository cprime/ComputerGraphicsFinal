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
#import "KeyboardHandler.h"
#import "Scene.h"

class Director {
public:
    static Director *SharedDirector();
    
    KeyboardHandler * get_keyboardHandler();
    
    void update();
private:
    KeyboardHandler *keyboardHandler;
    Scene *runningScene;
    
    float dt;
    clock_t lastUpdate;
    
    Director();
    Director(Director const&);             // copy constructor is private
    Director& operator=(Director const&);  // assignment operator is private
    static Director* m_pInstance;
    
    void calculateDeltaTime();
};

#endif /* defined(__Project__Director__) */
