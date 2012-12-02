//
//  CPoint.h
//  Project
//
//  Created by Colden Prime on 12/2/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__CPoint__
#define __Project__CPoint__

#import <GLUT/GLUT.h>

typedef struct {
    GLfloat x;
    GLfloat y;
    GLfloat z;
} CPoint;

CPoint CPointMake(GLfloat x, GLfloat y, GLfloat z);

CPoint CPointAdd(CPoint a, CPoint b);
CPoint CPointSub(CPoint a, CPoint b);
CPoint CPointMult(CPoint a, GLfloat scaler);

GLfloat CPointDistance(CPoint a, CPoint b);

bool CPointEqualToPoint(CPoint a, CPoint b);

extern const CPoint CPointZero;

#endif /* defined(__Project__CPoint__) */
