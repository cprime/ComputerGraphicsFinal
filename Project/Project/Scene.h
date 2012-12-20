//
//  Scene.h
//  Project
//
//  Created by Colden Prime on 12/9/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__Scene__
#define __Project__Scene__

#include "Node.h"

class Scene : public Node {
public:
    Scene();
    
    virtual void onEnter();
    
    void draw();
};

#endif /* defined(__Project__Scene__) */
