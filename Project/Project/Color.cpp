//
//  Color.cpp
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "Color.h"

const Color ColorWhite = (Color){1.0,1.0,1.0};
const Color ColorBlack = (Color){0,0,0};

Color ColorMake(GLfloat red, GLfloat green, GLfloat blue) {
    Color c;
    c.r = red;
    c.g = green;
    c.b = blue;
    return c;
}