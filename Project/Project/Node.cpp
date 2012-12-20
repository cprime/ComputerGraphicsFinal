//
//  Node.cpp
//  Project
//
//  Created by Colden Prime on 12/2/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "Node.h"
#include "Action.h"
#include "ActionManager.h"

#pragma mark - setters and getters

GLfloat Node::get_angleX() {
    return this->angleX;
}
void Node::set_angleX(GLfloat angleX) {
    this->angleX = angleX;
}
GLfloat Node::get_angleY() {
    return this->angleY;
}
void Node::set_angleY(GLfloat angleY) {
    this->angleY = angleY;
}
GLfloat Node::get_angleZ() {
    return this->angleZ;
}
void Node::set_angleZ(GLfloat angleZ) {
    this->angleZ = angleZ;
}

GLfloat Node::get_scaleX() {
    return this->scaleX;
}
void Node::set_scaleX(GLfloat scaleX) {
    this->scaleX = scaleX;
}
GLfloat Node::get_scaleY() {
    return this->scaleY;
}
void Node::set_scaleY(GLfloat scaleY) {
    this->scaleY = scaleY;
}
GLfloat Node::get_scaleZ() {
    return this->scaleZ;
}
void Node::set_scaleZ(GLfloat scaleZ) {
    this->scaleZ = scaleZ;
}

GLfloat Node::get_scale() {
    return scaleX;
}
void Node::set_scale(GLfloat scale) {
    this->scaleX = this->scaleY = this->scaleZ = scale;
}

Point Node::get_position() {
    return this->position;
}
void Node::set_position(Point position) {
    this->position = position;
}
Color Node::get_color() {
    return this->color;
}
void Node::set_color(Color color) {
    this->color = color;
}

Size Node::get_contentSize() {
    return this->contentSize;
}
void Node::set_contentSize(Size contentSize) {
    this->contentSize = contentSize;
}

Point Node::get_anchorPoint() {
    return this->anchorPoint;
}
void Node::set_anchorPoint(Point anchorPoint) {
    this->anchorPoint = anchorPoint;
}

Node * Node::get_parent() {
    return this->parent;
}
vector<Node *> * Node::get_children() {
    return this->children;
}

vector<Action *> * Node::get_actions() {
    return this->actions;
}
void Node::addAction(Action *action) {
    this->actions->push_back(action);
}
void Node::removeAction(Action *action) {
    std::vector<Action *>::iterator it = find(this->actions->begin(), this->actions->end(), action);
    if(it != this->actions->end()) {
        this->actions->erase(it);
    }
}

#pragma mark - init

Node::Node() {
    this->angleX = 0;
    this->angleY = 0;
    this->angleZ = 0;
    
    this->scaleX = 1;
    this->scaleY = 1;
    this->scaleZ = 1;
    
    this->position = PointZero;
    this->color = ColorWhite;
    this->contentSize = SizeZero;
    this->anchorPoint = PointMake(.5, .5, .5);
    
    this->actions = new vector<Action *>();
    this->children = new vector<Node *>();
    this->parent = NULL;
}
Node::~Node() {
    delete this->children;
    delete this->actions;
}

void Node::addChild(Node *node) {
    if(node) {
        if(find(this->children->begin(), this->children->end(), node) == this->children->end()) {
            this->children->push_back(node);
            node->parent = this;
        }
    }
}
void Node::removeFromParent() {
    if(this->parent) {
        this->children->erase(remove(this->children->begin(), this->children->end(), this), this->children->end());
        this->parent = NULL;
    }
}

#pragma mark - drawing
void Node::transform() {
    if(!PointEqualToPoint(this->position, PointZero)) {
        glTranslatef(this->position.x, this->position.y, this->position.z);
    }
    
    if(this->angleX != 0 || this->angleY != 0 || this->angleZ != 0) {
        glRotatef(this->angleX, 1.0, 0.0, 0.0);
        glRotatef(this->angleY, 0.0, 1.0, 0.0);
        glRotatef(this->angleZ, 0.0, 0.0, 1.0);
    }
    
    if(this->scaleX != 1 || this->scaleY != 1 || this->scaleZ != 1) {
        glScalef(this->scaleX, this->scaleY, this->scaleZ);
    }
    
    Point scaledAnchorPoint = PointMake(this->contentSize.width * this->anchorPoint.x,
                                        this->contentSize.height * this->anchorPoint.y,
                                        this->contentSize.depth * this->anchorPoint.z);
    glTranslatef(-scaledAnchorPoint.x, -scaledAnchorPoint.y, -scaledAnchorPoint.z);
}

void Node::draw() {
    //Override this method
}

void Node::visit() {
    glPushMatrix();
    glColor3f(this->color.r, this->color.g, this->color.b);
    
    this->transform();
    
    this->draw();
    
    for(vector<Node *>::iterator it = this->children->begin(); it != this->children->end(); ++it) {
        Node *node = *it;
        node->visit();
    }
    
    glColor3f(ColorWhite.r, ColorWhite.g, ColorWhite.b);
    glPopMatrix();
}

#pragma mark - action methods

void Node::runAction(Action *action) {
    ActionManager::SharedManager()->addAction(this, action);
}
void Node::stopAllActions() {
    ActionManager::SharedManager()->removeAllActions(this);
}
void Node::stopAction(Action *action) {
    ActionManager::SharedManager()->removeAction(this, action);
}
void Node::stopActionWithTag(int tag) {
    ActionManager::SharedManager()->removeActionWithTag(this, tag);
}

