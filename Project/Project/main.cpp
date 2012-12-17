//
//  main.cpp
//  Project
//
//  Created by Colden Prime on 11/29/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include <GLUT/GLUT.h>
#import "Director.h"
#import "KeyboardHandler.h"
#import "TestScene.h"

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the window
    Director::SharedDirector()->update();
    glFlush();
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat) w/(GLfloat) h, 1.0, 80.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-20, 20, 0, 0, 0, 0, 0, 1, 0);
}
/* Rotate about x-axis when "x" typed; rotate about y-axis when "y" typed; "i" returns torus to original view */
void keyboard(unsigned char key, int x, int y) {
    KeyboardHandler::Instance()->KeyPressed(key, true);
}
void keyboardUp(unsigned char key, int x, int y) {
    KeyboardHandler::Instance()->KeyPressed(key, false);
}
int main(int argc, char **argv) {
	glutInitWindowSize(950, 700);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow(argv[0]);

	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
	glutDisplayFunc(display);
    glutIdleFunc(display);
	
	
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
    
    TestScene *scene = new TestScene();
    scene->set_position(PointMake(0.0, -5., 0));
	Director::SharedDirector()->runScene(scene);
    
	glutMainLoop();
	return 0;
    
}

