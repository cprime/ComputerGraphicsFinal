//
//  VectorMan.cpp
//  Project
//
//  Created by Colden Prime on 12/10/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "VectorMan.h"

VectorMan::VectorMan() : Node() {
    
}

void VectorMan::draw() {
    Node::draw();
    
    //Override this method
    glColor3f(1.0f, 1.0f, 1.0f);
    glutWireCube(2.0f); // Plot Solid Objects
}