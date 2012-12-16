//
//  MinerArm.cpp
//  Project
//
//  Created by Colden Prime on 12/16/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "MinerArm.h"

MinerArm::MinerArm() : Node() {
    this->set_contentSize(SizeMake(2, 6, 2));
}

void MinerArm::draw() {
    Node::draw();
    
    glColor3f(0, 1.0, 1.0);
    
    glPushMatrix();
    glTranslatef(1.0, 4.0, 1.0);
    glScalef(2, 4, 2);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glColor3f(0.6, 0.4, 0.3);
    
    glPushMatrix();
    glTranslatef(1.0, 1.0, 1.0);
    glScalef(2, 2, 2);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glColor3f(1.0, 1.0, 1.0);
}