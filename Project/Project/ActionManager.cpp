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
}