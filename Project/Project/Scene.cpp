//
//  Scene.cpp
//  Project
//
//  Created by Colden Prime on 12/9/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "Scene.h"

Scene::Scene() : Node::Node() {
    
}

void Scene::draw() {
    Node::draw();
    
    //Override this method
    glColor3f(1.0f, 1.0f, 1.0f);
    glutWireCube(2.0f); // Plot Solid Objects
}

void Scene::keyPressed(char key) {
    switch (key) {
        case 'x':
        case 'X':
            glRotatef(30.,1.0,0.0,0.0);
            break;
        case 'z':
        case 'Z':
            glRotatef(30.,0.0,1.0,0.0);
            break;
        case 'c':
        case 'C':
            glRotatef(30.,0.0,0.0,1.0);
            break;
        case 'i':
        case 'I':
            glLoadIdentity();
            gluLookAt(0, 0, 30, 0, 0, 0, 0, 1, 0);
            break;
        case 27:
            exit(0);
            break;
	}
}