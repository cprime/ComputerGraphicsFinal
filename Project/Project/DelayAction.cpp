//
//  DelayAction.cpp
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "DelayAction.h"
#include "Node.h"

DelayAction::DelayAction(float duration) : Action(duration) {
}

void DelayAction::startWithTarget(Node *node) {
    Action::startWithTarget(node);
}
void DelayAction::finish() {
    Action::finish();
}

void DelayAction::update(float t) {
    Action::update(t);
}