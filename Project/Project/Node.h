//
//  Node.h
//  Project
//
//  Created by Colden Prime on 12/2/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__Node__
#define __Project__Node__

#import <GLUT/GLUT.h>
#import <vector>
#import "Point.h"
#include "Color.h"

using namespace std;

class Node;
class Action;

class Node {
    GLfloat angleX, angleY, angleZ;
    GLfloat scaleX, scaleY, scaleZ;
    Point position;
    Color color;
    
    Node *parent;
    vector<Node *> *children;
    vector<Action *> *actions;
    
    void transform();
    
protected:
    virtual void draw();
    
public:
    GLfloat get_angleX();
    void set_angleX(GLfloat angleX);
    
    GLfloat get_angleY();
    void set_angleY(GLfloat angleY);
    
    GLfloat get_angleZ();
    void set_angleZ(GLfloat angleZ);
    
    GLfloat get_scaleX();
    void set_scaleX(GLfloat scaleX);
    
    GLfloat get_scaleY();
    void set_scaleY(GLfloat scaleY);
    
    GLfloat get_scaleZ();
    void set_scaleZ(GLfloat scaleZ);
    
    GLfloat get_scale();
    void set_scale(GLfloat scale);
    
    Point get_position();
    void set_position(Point position);
    
    Color get_color();
    void set_color(Color color);
    
    Node * get_parent();
    vector<Node *> * get_children();
    
    vector<Action *> * get_actions();
    void addAction(Action *);
    void removeAction(Action *);
    
    Node();
    virtual void visit();
    
    void addChild(Node *node);
    void removeFromParent();
    
    void runAction(Action *action);
    void stopAllActions();
    void stopAction(Action *action);
    void stopActionWithTag(int tag);
};

#endif /* defined(__Project__Node__) */
