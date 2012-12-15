//
//  VectorMan.h
//  Project
//
//  Created by Colden Prime on 12/10/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__VectorMan__
#define __Project__VectorMan__

#include "Node.h"
#import "NodeCube.h"
#import "ArmNode.h"

class VectorMan : public Node {
    NodeCube *torso;
    NodeCube *head;
    NodeCube *leftArm;
    NodeCube *rightArm;
    NodeCube *leftLeg;
    NodeCube *rightLeg;
public:
    VectorMan();
    void draw();
    
    void startWalkAnimation();
};

#endif /* defined(__Project__VectorMan__) */
