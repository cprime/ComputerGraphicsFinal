//
//  CNode.h
//  Project
//
//  Created by Colden Prime on 12/2/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__CNode__
#define __Project__CNode__

#import <GLUT/GLUT.h>
#import "CPoint.h"
#import <vector>

using namespace std;

class CNode;

class CNode {
    
    GLfloat scaleX, scaleY, scaleZ;
    CPoint position;
    
    CNode *parent;
    vector<CNode *> *children;
    
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
    
    CPoint get_position();
    void set_position(CPoint position);
    
    CNode * get_parent();
    vector<CNode *> * get_children();
    
    CNode();
    void visit();
    
    void addChild(CNode *node);
    void removeFromParent();
};

#endif /* defined(__Project__CNode__) */
