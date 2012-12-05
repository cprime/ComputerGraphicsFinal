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
#import "Point.h"
#import <vector>

using namespace std;

class Node;

class Node {
    
    GLfloat scaleX, scaleY, scaleZ;
    Point position;
    
    Node *parent;
    vector<Node *> *children;
    
    void draw();
    void transform();
    
public:
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
    
    Node * get_parent();
    vector<Node *> * get_children();
    
    Node();
    void visit();
    
    void addChild(Node *node);
    void removeFromParent();
};

#endif /* defined(__Project__Node__) */
