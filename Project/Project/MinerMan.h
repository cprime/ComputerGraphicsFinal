//
//  MinerMan.h
//  Project
//
//  Created by Colden Prime on 12/10/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__MinerMan__
#define __Project__MinerMan__

#include "Node.h"
#import "NodeCube.h"
#import "MinerArm.h"
#import "MinerLeg.h"

class MinerMan : public Node {
    NodeCube *torso;
    NodeCube *head;
    MinerArm *leftArm;
    MinerArm *rightArm;
    MinerLeg *leftLeg;
    MinerLeg *rightLeg;
public:
    MinerMan();
    void draw();
    
    void startWalkAnimation();
};

#endif /* defined(__Project__MinerMan__) */
