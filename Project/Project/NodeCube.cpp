//
//  NodeCube.cpp
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "NodeCube.h"

NodeCube::NodeCube() : Node() {
}

void NodeCube::draw() {
    Node::draw();
    
    glutWireCube(1.0f);
}