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
class MinerArm;
class MinerLeg;
class MinerTorso;
class MinerHead;

class MinerMan : public Node {
public:
    MinerTorso *torso;
    MinerHead *head;
    MinerArm *leftArm;
    MinerArm *rightArm;
    MinerLeg *leftLeg;
    MinerLeg *rightLeg;
    
    bool queuedStep;
    bool walking;
    bool lastStepLeft;
    
    MinerMan();
    ~MinerMan();
    void draw();
    
    void startWalkAnimation();
};

class MinerArm : public Node {
public:
    MinerArm();
    void draw();
};

class MinerLeg : public Node {
public:
    MinerLeg();
    void draw();
};

class MinerTorso : public Node {
public:
    MinerTorso();
    void draw();
};

class MinerHead : public Node {
public:
    MinerHead();
    void draw();
};

#endif /* defined(__Project__MinerMan__) */
