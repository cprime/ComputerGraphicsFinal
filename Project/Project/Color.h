//
//  Color.h
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__Color__
#define __Project__Color__

#include <GLUT/GLUT.h>

typedef struct {
    GLfloat r;
    GLfloat g;
    GLfloat b;
} Color;

Color ColorMake(GLfloat red, GLfloat green, GLfloat blue);

extern const Color ColorWhite;
extern const Color ColorBlack;

#endif /* defined(__Project__Color__) */
