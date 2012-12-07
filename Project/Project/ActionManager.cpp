//
//  ActionManager.cpp
//  Project
//
//  Created by Colden Prime on 12/5/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#include "ActionManager.h"

ActionManager * ActionManager::m_pInstance = NULL;

ActionManager * ActionManager::SharedManager()
{
    if (!m_pInstance)
        m_pInstance = new ActionManager;
    
    return m_pInstance;
}

ActionManager::ActionManager(ActionManager const & other)
{
}

ActionManager & ActionManager::operator= (const ActionManager & other)
{
    return *this;
}

ActionManager::ActionManager()
{
    this->targets = new vector<Node *, vector<Action *>>();
}

#pragma mark - running/stopping actions

void ActionManager::update(float dt) {
    
}

void ActionManager::addAction(Node *target, Action *action) {
}
void ActionManager::removeAllActions(Node *target) {
    
}
void ActionManager::removeAction(Node *target, Action *action) {
    
}
void ActionManager::removeActionWithTag(Node *node, int tag) {
    
}