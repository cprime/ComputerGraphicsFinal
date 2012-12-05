//
//  ActionManager.h
//  Project
//
//  Created by Colden Prime on 12/5/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__ActionManager__
#define __Project__ActionManager__

#include <vector>

class ActionManager {
public:
    static ActionManager *SharedManager();
private:
    ActionManager();
    ActionManager(ActionManager const&);             // copy constructor is private
    ActionManager& operator=(ActionManager const&);  // assignment operator is private
    static ActionManager* m_pInstance;
};

#endif /* defined(__Project__ActionManager__) */
