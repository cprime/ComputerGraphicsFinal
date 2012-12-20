//
//  SequenceAction.h
//  Project
//
//  Created by Colden Prime on 12/11/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__SequenceAction__
#define __Project__SequenceAction__

#include "Action.h"
#include <vector>

class SequenceAction : public Action {
    std::vector<Action *> *actions;
    int current;
    float finishedElapsed;
    bool currentStarted;

public:
    SequenceAction(std::vector<Action *> *actions);
    void startWithTarget(Node *node);
    void update(float t);
};

#endif /* defined(__Project__SequenceAction__) */
