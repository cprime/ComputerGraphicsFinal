//
//  Point.cpp
//  Project
//
//  Created by Colden Prime on 12/2/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "Point.h"
#include <math.h>

const Point PointZero = (Point){0,0,0};

Point PointMake(GLfloat x, GLfloat y, GLfloat z) {
    Point p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

Point PointAdd(Point a, Point b) {
    return PointMake(a.x + b.x, a.y + b.y, a.z + b.z);
}
Point PointSub(Point a, Point b) {
    return PointMake(a.x - b.x, a.y - b.y, a.z - b.z);
}
Point PointMult(Point a, GLfloat scaler) {
    return PointMake(a.x * scaler, a.y * scaler, a.z * scaler);
}

GLfloat PointDistance(Point a, Point b) {
    Point origin = PointSub(a, b);
    return sqrtf((origin.x * origin.x) + (origin.y * origin.y) + (origin.z * origin.z));
}

bool PointEqualToPoint(Point a, Point b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}