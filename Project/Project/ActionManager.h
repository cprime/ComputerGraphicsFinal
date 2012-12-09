//
//  ActionManager.h
//  Project
//
//  Created by Colden Prime on 12/5/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__ActionManager__
#define __Project__ActionManager__

#import <vector>
#import "Node.h"
#import "Action.h"

class ActionManager {
public:
    static ActionManager *SharedManager();
    
    void update(float dt);
    
    void addAction(Node *target, Action *action);
    void removeAllActions(Node *target);
    void removeAction(Node *target, Action *action);
    void removeActionWithTag(Node *node, int tag);
private:
    std::vector<Node *> *targets;
    
    ActionManager();
    ActionManager(ActionManager const&);             // copy constructor is private
    ActionManager& operator=(ActionManager const&);  // assignment operator is private
    static ActionManager* m_pInstance;
};

#endif /* defined(__Project__ActionManager__) */
