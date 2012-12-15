//
//  CallFuncAction.cpp
//  Project
//
//  Created by Colden Prime on 12/13/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "CallFuncAction.h"
#import "Node.h"

CallFuncAction::CallFuncAction(void (*func_callback)()) : Action() {
    this->func_callback = func_callback;
    this->func_callbackN = NULL;
}
CallFuncAction::CallFuncAction(void (*func_callbackN)(Node *)) : Action() {
    this->func_callback = NULL;
    this->func_callbackN = func_callbackN;
}

void CallFuncAction::step(float dt) {
    this->update(1);
}
void CallFuncAction::update(float t) {
    Action::update(t);

    this->execute();
}
void CallFuncAction::finish() {
    if(!this->isFinished()) {
        Action::finish();
        
        this->execute();
    }
}
void CallFuncAction::execute() {
    if(this->func_callback) {
        this->func_callback();
    } else {
        this->func_callbackN(this->get_target());
    }
}