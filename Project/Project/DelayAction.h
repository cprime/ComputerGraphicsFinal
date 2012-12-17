//
//  DelayAction.h
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__DelayAction__
#define __Project__DelayAction__

#import "Action.h"

class DelayAction : public Action {
public:
    DelayAction(float duration);
    void startWithTarget(Node *node);
    void update(float t);
    void finish();
};

#endif /* defined(__Project__DelayAction__) */
