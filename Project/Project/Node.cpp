//
//  Node.cpp
//  Project
//
//  Created by Colden Prime on 12/2/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#import "Node.h"
#import "Action.h"
#import "ActionManager.h"

#pragma mark - setters and getters
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
    this->scaleX = 1;
    this->scaleY = 1;
    this->scaleZ = 1;
    
    this->position = PointZero;
    
    this->actions = new vector<Action *>();
    this->children = new vector<Node *>();
    this->parent = NULL;
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
    
    if(this->scaleX != 1 || this->scaleY != 1 || this->scaleZ != 1) {
        glScalef(this->scaleX, this->scaleY, this->scaleZ);
    }
}

void Node::draw() {
    //Override this method
}

void Node::visit() {
    glPushMatrix();
    
    this->transform();
    
    this->draw();
    
    for(vector<Node *>::iterator it = this->children->begin(); it != this->children->end(); ++it) {
        Node *node = *it;
        node->visit();
    }
    
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

