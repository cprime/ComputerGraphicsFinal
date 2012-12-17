//
//  KeyboardHandler.h
//  Project
//
//  Created by Colden Prime on 12/5/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__KeyboardHandler__
#define __Project__KeyboardHandler__

#include <iostream>
#include <map>
#include <set>
#include "KeyboardListener.h"

using namespace std;

class KeyboardHandler {
public:
    static KeyboardHandler* Instance();
    
    void KeyPressed(char key, bool down);
    void AddListener(KeyboardListener* listener, char key);
    void RemoveListener(KeyboardListener* listener, char key);
    void RemoveListener(KeyboardListener* listener);
    
protected:
    KeyboardHandler(); // CTor
    
private:
    static KeyboardHandler* singletonInstance;
    std::map<char, std::set<KeyboardListener*>> keyboardListeners;
};

#endif /* defined(__Project__KeyboardHandler__) */
