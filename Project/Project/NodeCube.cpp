//
//  NodeCube.cpp
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "NodeCube.h"

NodeCube::NodeCube() : Node() {
    this->set_contentSize(SizeMake(1, 1, 1));
}

void NodeCube::draw() {
    Node::draw();
    
    glPushMatrix();
    glTranslatef(.5, .5, .5);
    glutSolidCube(1.0f);
    glPopMatrix();
    
//    glColor3f(0.0, 1.0, 1.0);
//    glBegin(GL_LINE_LOOP);
//        glVertex3f(0.0f, 0.0f, 0.0f);
//        glVertex3f(1.0f, 0.0f, 0.0f);
//        glVertex3f(1.0f, 1.0f, 0.0f);
//        glVertex3f(0.0f, 1.0f, 0.0f);
//    glEnd();
}