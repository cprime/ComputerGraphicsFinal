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
    std::vector<Node *>::iterator it = this->targets->begin();
    for( ; it != this->targets->end(); ) {
        Node *node = *it;
        vector<Action *> *actions = node->get_actions();
        
        std::vector<Action *>::iterator actionIt = actions->begin();
        for( ; actionIt != actions->end(); ) {
            Action *action = *actionIt;

            long int before = actions->size();
            action->step(dt);
            
            if(before < actions->size()) {
                printf("diff\n");
                actionIt = find(actions->begin(), actions->end(), action);
            } else if(before > actions->size()) {
                printf("fix this!\n");
            }
            
            if(action->isFinished()) {
                actionIt = actions->erase(actionIt);
            } else {
                ++actionIt;
            }
        }
        
        if(actions->empty()) {
            it = this->targets->erase(it);
        } else {
            ++it;
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