//
//  Point.h
//  Project
//
//  Created by Colden Prime on 12/2/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__Point__
#define __Project__Point__

#import <GLUT/GLUT.h>

typedef struct {
    GLfloat x;
    GLfloat y;
    GLfloat z;
} Point;

Point PointMake(GLfloat x, GLfloat y, GLfloat z);

Point PointAdd(Point a, Point b);
Point PointSub(Point a, Point b);
Point PointMult(Point a, GLfloat scaler);

GLfloat PointDistance(Point a, Point b);

bool PointEqualToPoint(Point a, Point b);

extern const Point PointZero;

#endif /* defined(__Project__Point__) */
