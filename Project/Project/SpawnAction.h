//
//  SpawnAction.h
//  Project
//
//  Created by Colden Prime on 12/12/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__SpawnAction__
#define __Project__SpawnAction__

#include "Action.h"
#include <vector>

class SpawnAction : public Action {
    std::vector<Action *> *actions;
    
public:
    SpawnAction(std::vector<Action *> *actions);
    void startWithTarget(Node *node);
    void update(float t);
};

#endif /* defined(__Project__SpawnAction__) */
