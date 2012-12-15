//
//  ArmNode.cpp
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "ArmNode.h"

ArmNode::ArmNode() : Node() {
}

void ArmNode::draw() {
    Node::draw();
    
    glTranslatef(0, -2, 0);
    glScalef(2.0, 6.0, 2.0);
    glutWireCube(1.0);
}