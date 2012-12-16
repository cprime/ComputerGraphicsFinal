//
//  MinerLeg.cpp
//  Project
//
//  Created by Colden Prime on 12/16/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "MinerLeg.h"

MinerLeg::MinerLeg() : Node() {
    this->set_contentSize(SizeMake(2, 5, 2));
}

void MinerLeg::draw() {
    Node::draw();
    
    glColor3f(0.15, 0.4, 0.7);
    
    glPushMatrix();
    glTranslatef(1.0, 3.0, 1.0);
    glScalef(2, 4, 2);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glColor3f(0.2, 0.2, 0.2);
    
    glPushMatrix();
    glTranslatef(1.0, 0.5, 1.0);
    glScalef(2, 1, 2);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glColor3f(1.0, 1.0, 1.0);
}