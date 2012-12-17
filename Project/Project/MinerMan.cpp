//
//  MinerMan.cpp
//  Project
//
//  Created by Colden Prime on 12/10/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "MinerMan.h"
#import "RotateToAction.h"
#import "SequenceAction.h"
#import "RepeatAction.h"
#import "CallFuncAction.h"
#import "DelayAction.h"

#define LegSpeed 0.25
#define LegAngle 30.0

void halfStep(MinerMan *man);

void finishedStep(Node *node) {
    printf("finishedStep\n");
    MinerMan *man = (MinerMan *)node;
    
    man->lastStepLeft = man->lastStepLeft == false;
    man->walking = false;
    
    if(man->queuedStep) {
        halfStep(man);
    }
}

void halfStep(MinerMan *man) {
    printf("half step\n");
    man->walking = true;
    
    std::vector<Action *> *actions;
    RotateToAction *rotateAction;
    SequenceAction *sequenceAction;
    
    float leftLegAngle = -LegAngle;
    float rightArmAngle = -LegAngle;
    
    float rightLegAngle = LegAngle;
    float leftArmAngle = LegAngle;
    if(man->lastStepLeft) {
        leftLegAngle = LegAngle;
        rightArmAngle = LegAngle;
        
        rightLegAngle = -LegAngle;
        leftArmAngle = -LegAngle;
    }
    
    //left leg and right arm
    actions = new std::vector<Action *>;
    
    rotateAction = new RotateToAction(LegSpeed, 0.0, 0.0, leftLegAngle);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(LegSpeed, 0.0, 0.0, 0);
    actions->push_back(rotateAction);
    
    sequenceAction = new SequenceAction::SequenceAction(actions);
    man->leftLeg->runAction(sequenceAction);
    
    actions = new std::vector<Action *>;
    
    rotateAction = new RotateToAction(LegSpeed, 0.0, 0.0, rightArmAngle);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(LegSpeed, 0.0, 0.0, 0);
    actions->push_back(rotateAction);
    
    sequenceAction = new SequenceAction::SequenceAction(actions);
    man->rightArm->runAction(sequenceAction);
    
    //right leg and left arm
    
    actions = new std::vector<Action *>;
    
    rotateAction = new RotateToAction(LegSpeed, 0.0, 0.0, rightLegAngle);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(LegSpeed, 0.0, 0.0, 0);
    actions->push_back(rotateAction);
    
    sequenceAction = new SequenceAction::SequenceAction(actions);
    man->rightLeg->runAction(sequenceAction);
    
    actions = new std::vector<Action *>;
    
    rotateAction = new RotateToAction(LegSpeed, 0.0, 0.0, leftArmAngle);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(LegSpeed, 0.0, 0.0, 0);
    actions->push_back(rotateAction);
    
    sequenceAction = new SequenceAction::SequenceAction(actions);
    man->leftArm->runAction(sequenceAction);
    
    //man
    actions = new std::vector<Action *>;
    
    DelayAction *delayAction = new DelayAction::DelayAction(LegSpeed * 2);
    actions->push_back(delayAction);
    
    CallFuncAction *callFunc = new CallFuncAction::CallFuncAction(&finishedStep);
    actions->push_back(callFunc);
    
    sequenceAction = new SequenceAction::SequenceAction(actions);
    man->runAction(sequenceAction);
    
    man->queuedStep = false;
}

MinerMan::MinerMan() : Node() {
    this->queuedStep = false;
    this->walking = false;
    this->lastStepLeft = false;
    
    this->head = new MinerHead();
    this->head->set_position(PointMake(4, 12, 4));
    this->head->set_anchorPoint(PointMake(.5, .5, .5));
    this->addChild(this->head);

    this->torso = new MinerTorso();
    this->torso->set_position(PointMake(4, 7.5, 4));
    this->torso->set_anchorPoint(PointMake(.5, .5, .5));
    this->addChild(this->torso);
    
    this->leftArm = new MinerArm();
    this->leftArm->set_position(PointMake(4, 9, 7.0));
    this->leftArm->set_anchorPoint(PointMake(0.5, .833, 0.5));
    this->addChild(this->leftArm);
    
    this->rightArm = new MinerArm();
    this->rightArm->set_position(PointMake(4, 9, 1.0));
    this->rightArm->set_anchorPoint(PointMake(0.5, .833, 0.5));
    this->addChild(this->rightArm);
    
    this->leftLeg = new MinerLeg();
    this->leftLeg->set_position(PointMake(4, 6, 5.0));
    this->leftLeg->set_anchorPoint(PointMake(0.5, 1.0, 0.5));
    this->addChild(this->leftLeg);
    
    this->rightLeg = new MinerLeg();
    this->rightLeg->set_position(PointMake(4, 6, 3.0));
    this->rightLeg->set_anchorPoint(PointMake(.5, 1.0, .5));
    this->addChild(this->rightLeg);
    
    this->set_anchorPoint(PointMake(4, 0.5, 0.5));
    this->set_contentSize(SizeMake(8, 13, 8));
}

MinerMan::~MinerMan() {
    delete this->head;
    delete this->torso;
    delete this->leftArm;
    delete this->rightArm;
    delete this->leftLeg;
    delete this->rightLeg;
}

void MinerMan::draw() {
    Node::draw();
    
    glPushMatrix();
    glScalef(this->get_contentSize().width, this->get_contentSize().height, this->get_contentSize().depth);
    glTranslatef(.5, .5, .5);
    glutWireCube(1);
    glPopMatrix();
    
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(.5, 0, .5);
    glVertex3f(-.5, 0, .5);
    glVertex3f(-.5, 0, -.5);
    glVertex3f(.5, 0, -.5);
    glEnd();
}

void MinerMan::startWalkAnimation() {
    printf("step queued\n");
    
    this->queuedStep = true;
    if(!this->walking) {
        halfStep(this);
    }
}

#pragma mark - MinerArm

MinerArm::MinerArm() : Node() {
    this->set_contentSize(SizeMake(2, 5, 2));
}

void MinerArm::draw() {
    Node::draw();
    
    glColor3f(0, 1.0, 1.0);
    
    glPushMatrix();
    glTranslatef(1.0, 3.25, 1.0);
    glScalef(2, 3.5, 2);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glColor3f(0.6, 0.4, 0.3);
    
    glPushMatrix();
    glTranslatef(1.0, .75, 1.0);
    glScalef(2, 1.5, 2);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glColor3f(1.0, 1.0, 1.0);
}

#pragma mark - MinerLeg

MinerLeg::MinerLeg() : Node() {
    this->set_contentSize(SizeMake(2, 6, 2));
}

void MinerLeg::draw() {
    Node::draw();
    
    glColor3f(0.15, 0.4, 0.7);
    
    glPushMatrix();
    glTranslatef(1.0, 5.0, 1.0);
    glRotatef(45, 0, 0, 1.0);
    glScalef(1.41, 1.41, 2);
    glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.0, 3.0, 1.0);
    glScalef(2, 4, 2);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glColor3f(0.2, 0.2, 0.2);
    
    glPushMatrix();
    glTranslatef(1.0, 0.5, 1.0);
    glScalef(2, 1, 2);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glColor3f(1.0, 1.0, 1.0);
}

#pragma mark - MinerTorso

MinerTorso::MinerTorso() : Node() {
    this->set_contentSize(SizeMake(2, 5, 4));
}

void MinerTorso::draw() {
    Node::draw();
    
    glColor3f(0.15, 0.4, 0.7);
    
    glPushMatrix();
    glTranslatef(1.0, 0.5, 2.0);
    glScalef(2, 1, 4);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glColor3f(0, 1.0, 1.0);
    
    glPushMatrix();
    glTranslatef(1.0, 3.0, 2.0);
    glScalef(2, 4, 4);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glColor3f(1.0, 1.0, 1.0);
}

#pragma mark - MinerHead

MinerHead::MinerHead() : Node() {
    this->set_contentSize(SizeMake(4, 4, 4));
}

void MinerHead::draw() {
    Node::draw();
    
    //hair
    glColor3f(0.2, 0.2, 0.2);
    
    glPushMatrix();
    glTranslatef(2.0, 2.5, 2.0);
    glScalef(4, 1, 4);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1.0, 1.5, 2.0);
    glScalef(2, 1, 4);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    //head
    glColor3f(0.6, 0.4, 0.3);
    
    glPushMatrix();
    glTranslatef(2.0, 0.5, 2.0);
    glScalef(4, 1, 4);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(3.0, 1.5, 2.0);
    glScalef(2, 1, 4);
    glutSolidCube(1.0f);
    glPopMatrix();
    
    //face
    
    //nose
    glColor3f(0.6, 0.4, 0.3);
    glPushMatrix();
    glTranslatef(4.0, 1.0, 2.0);
    glRotatef(90, 0.0, 1.0, 0.0);
    glutSolidCone(.3, .5, 50, 50);
    glPopMatrix();
    
    //mouth
    glColor3f(1.0, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(4.0, 0.5, 2.0);
    glScalef(.3, .3, 1);
    glRotatef(90, 0.0, 1.0, 0.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    glutSolidCone(1, 1, 50, 50);
    glPopMatrix();
    
    //eyes
    glColor3f(0.2, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(4.0, 1.33, 1.33);
    glutSolidSphere(.25, 50, 50);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(4.0, 1.33, 2.67);
    glutSolidSphere(.25, 50, 50);
    glPopMatrix();
    
    glColor3f(1.0, 1.0, 1.0);
}





