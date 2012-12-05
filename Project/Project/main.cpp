//
//  main.cpp
//  Project
//
//  Created by Colden Prime on 11/29/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GLUT/GLUT.h>
#include "Point.h"
#include "Node.h"

Node *testObject;

/* Create display list with Torus and initialize state*/
static void init(void) {
    testObject = new Node();
    
    Node *child1 = new Node();
    child1->set_position(PointMake(5, 5, 0));
    child1->set_scale(.5);
    testObject->addChild(child1);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the window
    
    testObject->visit();
    
	//// Solid Objects
//	glPushMatrix();
//	glColor3f(0.5f, 0.7f, 1.0f); // Object Color
//	glTranslatef(3.0, 3.0, 0.0f); //  Object Position
//	glutSolidCube(2.0f); // Plot Solid Objects
//	glPopMatrix();
//    
//	glPushMatrix();
//	glColor3f(0.5f, 0.2f, 0.5f); // Object Color
//	glTranslatef(-3.0, 2.0, 0.0f); //  Object Position
//	glutSolidCube(3.0f); // Plot Solid Objects
//	glPopMatrix();
//    
//	glPushMatrix();
//	glColor3f(0.2f, 0.8f, 0.2f); // Object Color
//	glTranslatef(2.0, -2.0, 0.0f); //  Object Position
//	glutSolidSphere(2.0, 20, 20); // Plot Solid Objects
//	glPopMatrix();
//	
//	glPushMatrix();
//	glColor3f(1.0f, 0.5f, 0.7f); // Object Color
//	glTranslatef(-3.0, -3.0, -2.0f); //  Object Position
//	glutSolidCone(2.0, 5, 20,20); // Plot Solid Objects
//	glPopMatrix();
	
	
	glFlush();
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat) w/(GLfloat) h, 1.0, 80.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 30, 0, 0, 0, 0, 1, 0);
}
/* Rotate about x-axis when "x" typed; rotate about y-axis when "y" typed; "i" returns torus to original view */
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
        case '1':
            testObject->set_scale(testObject->get_scale() - .1);
            glutPostRedisplay();
            break;
        case '2':
            testObject->set_scale(testObject->get_scale() + .1);
            glutPostRedisplay();
            break;
        case 'x':
        case 'X':
            glRotatef(30.,1.0,0.0,0.0);
            glutPostRedisplay();
            break;
        case 'z':
        case 'Z':
            glRotatef(30.,0.0,1.0,0.0);
            glutPostRedisplay();
            break;
        case 'c':
        case 'C':
            glRotatef(30.,0.0,0.0,1.0);
            glutPostRedisplay();
            break;
        case 'i':
        case 'I':
            glLoadIdentity();
            gluLookAt(0, 0, 30, 0, 0, 0, 0, 1, 0);
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
            break;
	}
}
int main(int argc, char **argv) {
	glutInitWindowSize(950, 700);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	
	
	// LIGHTING and MATERIAL
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; // light position
	GLfloat light[] = {0.5, 0.5, 0.5 }; // Light Color
	GLfloat lmodel_ambient[] = { 0.5, 0.5, 0.5, 0.0 }; // Ambient Light Color
    
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; //
	GLfloat mat_shininess[] = { 50.0 }; //
	
	glShadeModel (GL_SMOOTH);
    
	glEnable(GL_LIGHTING); // 2) enable Phong lighting calculation
	glEnable(GL_LIGHT0); // 2) eight point sources ( radiating in all directions )
	glEnable(GL_DEPTH_TEST); // 2)
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); // 2) set light position
    
	glEnable(GL_COLOR_MATERIAL); // 3) enable color driven materials
    
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light ); // 4)
	glLightfv(GL_LIGHT0, GL_SPECULAR, light ); // 4)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient); // 4)
	
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); // set material properties
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); // set material properties
	
	glClearColor (0.0, 0.0, 0.0, 0.0);
	
	
	glutMainLoop();
	return 0;
    
}

