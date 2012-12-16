//
//  RepeatAction.h
//  Project
//
//  Created by Colden Prime on 12/15/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__RepeatAction__
#define __Project__RepeatAction__

#import "Action.h"

class RepeatAction : public Action {
    int times;
    Action *innerAction;
public:
    RepeatAction(Action *action, int timesToRepeat);
    void startWithTarget(Node *node);
    void step(float dt);
    void update(float t);
    void finish();
};

#endif /* defined(__Project__RepeatAction__) */
