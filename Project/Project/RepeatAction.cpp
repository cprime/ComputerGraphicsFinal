//
//  RepeatAction.cpp
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "RepeatAction.h"
#include <stdio.h>

RepeatAction::RepeatAction(Action *action, int timesToRepeat) : Action() {
    this->innerAction = action;
    this->times = timesToRepeat;
}
void RepeatAction::startWithTarget(Node *node) {
    Action::startWithTarget(node);
    this->innerAction->startWithTarget(node);
}
void RepeatAction::step(float dt) {
    this->innerAction->step(dt);
	if( this->innerAction->isFinished() ) {
		float diff = dt + innerAction->get_duration() - innerAction->get_elapsed();
		this->innerAction->startWithTarget(this->get_target());
		
        this->innerAction->step(diff);
	}
}
void RepeatAction::update(float t) {
    printf("wtf\n");
}
void RepeatAction::finish() {
    printf("wtf\n");
}