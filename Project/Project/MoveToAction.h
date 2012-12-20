//
//  MoveToAction.h
//  Project
//
//  Created by Colden Prime on 12/9/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__MoveToAction__
#define __Project__MoveToAction__

#include "Action.h"
#include "Point.h"

class MoveToAction : public Action {
    Point origin;
    Point delta;
    Point destination;
public:
    MoveToAction(float duration, Point destination);
    void startWithTarget(Node *node);
    void finish();
    void update(float t);
};

#endif /* defined(__Project__MoveToAction__) */
