//
//  Action.h
//  Project
//
//  Created by Colden Prime on 12/6/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__Action__
#define __Project__Action__

#define MIN(A,B) ((A < B) ? A : B)
#define MAX(A,B) ((A > B) ? A : B)

class Node;

class Action {
public:
    Action(float duration);
    
    virtual void startWithTarget(Node *node);
    virtual bool isDone();
    bool isFinished;
    
    void tick(float dt);
    virtual void update(float t);
    
    int tag;
    float duration;
    float elapsed;
protected:
    Node *target;
};

#endif /* defined(__Project__Action__) */
