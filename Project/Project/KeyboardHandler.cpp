//
//  KeyboardHandler.cpp
//  Project
//
//  Created by Colden Prime on 12/5/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "KeyboardHandler.h"
#import <GLUT/GLUT.h>

void KeyboardHandler::keyboardClicked(unsigned char key) {
	switch (key) {
        case 'z':
        case 'Z':
            glRotatef(30.,1.0,0.0,0.0);
            break;
        case 'x':
        case 'X':
            glRotatef(30.,0.0,1.0,0.0);
            break;
        case 'c':
        case 'C':
            glRotatef(30.,0.0,0.0,1.0);
            break;
        case 'i':
        case 'I':
            glLoadIdentity();
            gluLookAt(0, 0, 30, 0, 0, 0, 0, 1, 0);
            break;
        case 27:
            exit(0);
            break;
	}
}