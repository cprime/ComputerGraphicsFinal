//
//  Size.cpp
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "Size.h"

const Size SizeZero = (Size){0,0,0};

Size SizeMake(GLfloat width, GLfloat height, GLfloat depth) {
    Size s;
    s.width = width;
    s.height = height;
    s.depth = depth;
    return s;
}