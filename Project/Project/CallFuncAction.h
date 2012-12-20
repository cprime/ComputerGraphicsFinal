//
//  CallFuncAction.h
//  Project
//
//  Created by Colden Prime on 12/13/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__CallFuncAction__
#define __Project__CallFuncAction__

#include "Action.h"

class Node;

class CallFuncAction : public Action {
    void (*func_callback)();
    void (*func_callbackN)(Node *);
    
    void execute();
public:
    CallFuncAction(void (*func_callback)());
    CallFuncAction(void (*func_callbackN)(Node *));
    void step(float dt);
    void finish();
    void update(float t);
};

#endif /* defined(__Project__CallFuncAction__) */
