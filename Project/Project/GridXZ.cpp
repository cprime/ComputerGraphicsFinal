//
//  GridXZ.cpp
//  Project
//
//  Created by Colden Prime on 12/16/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "GridXZ.h"

#define GridBounds 100
#define GridIncrement 4

GridXZ::GridXZ() : Node() {
    this->set_contentSize(SizeMake(1, 1, 1));
}

void GridXZ::draw() {
    Node::draw();
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glLineWidth(1);
    
    for(int i = -GridBounds; i < GridBounds; i += GridIncrement) {
        glVertex3f(i, 0, -GridBounds);
        glVertex3f(i, 0, GridBounds);
    }
    
    for(int i = -GridBounds; i < GridBounds; i += GridIncrement) {
        glVertex3f(-GridBounds, 0, i);
        glVertex3f(GridBounds, 0, i);
    }
    
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(.5, 0, .5);
    glVertex3f(-.5, 0, .5);
    glVertex3f(-.5, 0, -.5);
    glVertex3f(.5, 0, -.5);
    glEnd();
}