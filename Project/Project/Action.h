//
//  Action.h
//  Project
//
//  Created by Colden Prime on 12/6/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__Action__
#define __Project__Action__

class Node;

class Action {
public:
    void update(float dt);
    
    int tag;
    Node *target;
private:
};

#endif /* defined(__Project__Action__) */
