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

MinerMan::MinerMan() : Node() {
    
    this->head = new MinerHead();
    this->head->set_position(PointMake(0, 12, 0));
    this->head->set_anchorPoint(PointMake(.5, .5, .5));
    this->addChild(this->head);

    this->torso = new MinerTorso();
    this->torso->set_position(PointMake(0, 7.5, 0));
    this->torso->set_anchorPoint(PointMake(.5, .5, .5));
    this->addChild(this->torso);
    
    this->leftArm = new MinerArm();
    this->leftArm->set_position(PointMake(0, 9, 3.0));
    this->leftArm->set_anchorPoint(PointMake(0.5, .833, 0.5));
    this->addChild(this->leftArm);
    
    this->rightArm = new MinerArm();
    this->rightArm->set_position(PointMake(0, 9, -3.0));
    this->rightArm->set_anchorPoint(PointMake(0.5, .833, 0.5));
    this->addChild(this->rightArm);
    
    this->leftLeg = new MinerLeg();
    this->leftLeg->set_position(PointMake(0, 6, 1.0));
    this->leftLeg->set_anchorPoint(PointMake(0.5, 1.0, 0.5));
    this->addChild(this->leftLeg);
    
    this->rightLeg = new MinerLeg();
    this->rightLeg->set_position(PointMake(0, 6, -1.0));
    this->rightLeg->set_anchorPoint(PointMake(.5, 1.0, .5));
    this->addChild(this->rightLeg);
    
    this->set_anchorPoint(PointMake(0, 0.5, 0.5));
    this->set_contentSize(SizeMake(12, 12, 12));
}

void MinerMan::draw() {
    Node::draw();
}

void MinerMan::startWalkAnimation() {
    std::vector<Action *> *actions;
    RotateToAction *rotateAction;
    SequenceAction *sequenceAction;
    RepeatAction *repeatAction;
    
    float legSpeed = .75;
    
    actions = new std::vector<Action *>;

    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, 30.0);
    actions->push_back(rotateAction);

    rotateAction = new RotateToAction(legSpeed, 0.0, 0.0, -30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, 0.0);
    actions->push_back(rotateAction);

    sequenceAction = new SequenceAction::SequenceAction(actions);
    repeatAction = new RepeatAction::RepeatAction(sequenceAction, 0);
    this->leftLeg->runAction(repeatAction);
    
    actions = new std::vector<Action *>;
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, -30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed, 0.0, 0.0, 30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, 0.0);
    actions->push_back(rotateAction);
    
    sequenceAction = new SequenceAction::SequenceAction(actions);
    repeatAction = new RepeatAction::RepeatAction(sequenceAction, 0);
    this->rightLeg->runAction(repeatAction);
    
    //arms
    actions = new std::vector<Action *>;
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, 30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed, 0.0, 0.0, -30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, 0.0);
    actions->push_back(rotateAction);
    
    sequenceAction = new SequenceAction::SequenceAction(actions);
    repeatAction = new RepeatAction::RepeatAction(sequenceAction, 0);
    this->rightArm->runAction(repeatAction);
    
    actions = new std::vector<Action *>;
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, -30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed, 0.0, 0.0, 30.0);
    actions->push_back(rotateAction);
    
    rotateAction = new RotateToAction(legSpeed / 2.0, 0.0, 0.0, 0.0);
    actions->push_back(rotateAction);
    
    sequenceAction = new SequenceAction::SequenceAction(actions);
    repeatAction = new RepeatAction::RepeatAction(sequenceAction, 0);
    this->leftArm->runAction(repeatAction);
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





