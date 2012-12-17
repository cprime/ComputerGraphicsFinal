//
//  KeyboardHandler.cpp
//  Project
//
//  Created by Colden Prime on 12/5/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "KeyboardHandler.h"

KeyboardHandler* KeyboardHandler::singletonInstance = NULL;

KeyboardHandler::KeyboardHandler() {
    /* Do whatever CTor stuff you wish */
}

KeyboardHandler* KeyboardHandler::Instance() {
    if (singletonInstance == NULL) {
        singletonInstance = new KeyboardHandler();
    }
    return singletonInstance;
}

void KeyboardHandler::KeyPressed(char key, bool down){
    std::set<KeyboardListener*>::iterator iit;
    
    std::set<KeyboardListener*> keySet =this->keyboardListeners[key];
    
    if (keySet.empty()) return;
    
    for (iit=keySet.begin(); iit != keySet.end(); iit++) {
        (*iit)->KeyPressed(this, key, down);
    }
}

void KeyboardHandler::AddListener(KeyboardListener* listener, char key){
    this->keyboardListeners[key].insert(listener);
}

void KeyboardHandler::RemoveListener(KeyboardListener* listener, char key){
    this->keyboardListeners[key].erase(listener);
}

void KeyboardHandler::RemoveListener(KeyboardListener* listener){
    std::map<char, std::set<KeyboardListener*>>::iterator iit;
    
    for (iit=this->keyboardListeners.begin(); iit != this->keyboardListeners.end(); iit++) {
        (*iit).second.erase(listener);
    }
    
}