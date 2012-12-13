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
    this->targets = new std::vector<Node *>();
}

#pragma mark - running/stopping actions

void ActionManager::update(float dt) {
    for(std::vector<Node *>::iterator it = this->targets->begin(); it != this->targets->end(); ++it) {
        Node *node = *it;
        vector<Action *> *actions = node->get_actions();
        
        std::vector<Action *>::iterator actionIt = actions->begin();
        for(; actionIt != actions->end(); ) {
            Action *action = *actionIt;
            action->tick(dt);
            
            if(action->isDone()) {
                actions->erase(actionIt);
                printf("done...\n");
            } else {
                ++actionIt;
            }
        }
    }
}

void ActionManager::addAction(Node *target, Action *action) {
    std::vector<Node *>::iterator it = find(this->targets->begin(), this->targets->end(), target);
    if(it == this->targets->end()) {
        this->targets->push_back(target);
    }
    target->addAction(action);
    action->startWithTarget(target);
}

void ActionManager::removeAllActions(Node *target) {
    std::vector<Node *>::iterator it = find(this->targets->begin(), this->targets->end(), target);
    if(it != this->targets->end()) {
        target->get_actions()->clear();
        this->targets->erase(it);
    }
    
}
void ActionManager::removeAction(Node *target, Action *action) {
    std::vector<Node *>::iterator it = find(this->targets->begin(), this->targets->end(), target);
    if(it != this->targets->end()) {
        std::vector<Action *> *actions = target->get_actions();
        
        if(actions->empty()) {
            this->targets->erase(it);
        }
    }
}
void ActionManager::removeActionWithTag(Node *node, int tag) {
    
}