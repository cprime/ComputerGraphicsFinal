//
//  Size.h
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__Size__
#define __Project__Size__

#import <GLUT/GLUT.h>

typedef struct {
    GLfloat width;
    GLfloat height;
    GLfloat depth;
} Size;

Size SizeMake(GLfloat width, GLfloat height, GLfloat depth);

extern const Size SizeZero;

#endif /* defined(__Project__Size__) */
