//
//  CPoint.cpp
//  Project
//
//  Created by Colden Prime on 12/2/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "CPoint.h"
#include <math.h>

const CPoint CPointZero = (CPoint){0,0,0};

CPoint CPointMake(GLfloat x, GLfloat y, GLfloat z) {
    CPoint p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

CPoint CPointAdd(CPoint a, CPoint b) {
    return CPointMake(a.x + b.x, a.y + b.y, a.z + b.z);
}
CPoint CPointSub(CPoint a, CPoint b) {
    return CPointMake(a.x - b.x, a.y - b.y, a.z - b.z);
}
CPoint CPointMult(CPoint a, GLfloat scaler) {
    return CPointMake(a.x * scaler, a.y * scaler, a.z * scaler);
}

GLfloat CPointDistance(CPoint a, CPoint b) {
    CPoint origin = CPointSub(a, b);
    return sqrtf((origin.x * origin.x) + (origin.y * origin.y) + (origin.z * origin.z));
}

bool CPointEqualToPoint(CPoint a, CPoint b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}