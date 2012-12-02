//
//  CNode.cpp
//  Project
//
//  Created by Colden Prime on 12/2/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "CNode.h"

#pragma mark - setters and getters
GLfloat CNode::get_scaleX() {
    return this->scaleX;
}
void CNode::set_scaleX(GLfloat scaleX) {
    this->scaleX = scaleX;
}
GLfloat CNode::get_scaleY() {
    return this->scaleY;
}
void CNode::set_scaleY(GLfloat scaleY) {
    this->scaleY = scaleY;
}
GLfloat CNode::get_scaleZ() {
    return this->scaleZ;
}
void CNode::set_scaleZ(GLfloat scaleZ) {
    this->scaleZ = scaleZ;
}

GLfloat CNode::get_scale() {
    return scaleX;
}
void CNode::set_scale(GLfloat scale) {
    this->scaleX = this->scaleY = this->scaleZ = scale;
}

CPoint CNode::get_position() {
    return this->position;
}
void CNode::set_position(CPoint position) {
    this->position = position;
}

CNode * CNode::get_parent() {
    return this->parent;
}
vector<CNode *> * CNode::get_children() {
    return this->children;
}

#pragma mark - init

CNode::CNode() {
    this->scaleX = 1;
    this->scaleY = 1;
    this->scaleZ = 1;
    
    this->position = CPointZero;
    
    this->children = new vector<CNode *>();
    this->parent = NULL;
}

void CNode::addChild(CNode *node) {
    if(node) {
        if(find(this->children->begin(), this->children->end(), node) == this->children->end()) {
            this->children->push_back(node);
            node->parent = this;
        }
    }
}
void CNode::removeFromParent() {
    if(this->parent) {
        this->children->erase(remove(this->children->begin(), this->children->end(), this), this->children->end());
        this->parent = NULL;
    }
}

#pragma mark - drawing
void CNode::transform() {
    if(!CPointEqualToPoint(this->position, CPointZero)) {
        glTranslatef(this->position.x, this->position.y, this->position.z);
    }
    
    if(this->scaleX != 1 || this->scaleY != 1 || this->scaleZ != 1) {
        glScalef(this->scaleX, this->scaleY, this->scaleZ);
    }
}

void CNode::draw() {
    //Override this method
//    glColor3f(1.0f, 1.0f, 1.0f);
    glColor4f(1.0, 1.0, 1.0, 0.5);
    glutSolidCube(2.0f); // Plot Solid Objects
}

void CNode::visit() {
    glPushMatrix();
    
    this->transform();
    
    this->draw();
    
    for(vector<CNode *>::iterator it = this->children->begin(); it != this->children->end(); ++it) {
        CNode *node = *it;
        node->visit();
    }
    
    glPopMatrix();
}

