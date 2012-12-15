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
    Action();
    Action(float duration);
    
    int get_tag();
    float get_duration();
    float get_elapsed();
    Node *get_target();
    bool isFinished();
    
    virtual void startWithTarget(Node *node);
    virtual void step(float dt);
    virtual void update(float t);
    virtual void finish();
    
private:
    int _tag;
    float _duration;
    float _elapsed;
    bool _finished;
    
    Node *_target;
};

#endif /* defined(__Project__Action__) */
