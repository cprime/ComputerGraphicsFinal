//
//  ScaleToAction.h
//  Project
//
//  Created by Colden Prime on 12/9/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__ScaleToAction__
#define __Project__ScaleToAction__

#import "Action.h"
#import "Point.h"

class ScaleToAction : public Action {
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
    ScaleToAction(float duration, float destination);
    ScaleToAction(float duration, float destinationX, float destinationY, float destinationZ);
    void startWithTarget(Node *node);
    void finish();
    void update(float t);
};

#endif /* defined(__Project__ScaleToAction__) */
