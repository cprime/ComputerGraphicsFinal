//
//  RotateToAction.h
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__RotateToAction__
#define __Project__RotateToAction__

#include "Action.h"
#include "Point.h"

class RotateToAction : public Action {
    float originX;
    float deltaX;
    float destinationX;
    float originY;
    float deltaY;
    float destinationY;
    float originZ;
    float deltaZ;
    float destinationZ;
public:
    RotateToAction(float duration, float destinationX, float destinationY, float destinationZ);
    void startWithTarget(Node *node);
    void finish();
    void update(float t);
};

#endif /* defined(__Project__RotateToAction__) */
