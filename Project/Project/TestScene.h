//
//  TestScene.h
//  Project
//
//  Created by Colden Prime on 12/10/12.
//  Copyright (c) 2012 IntrepidPursuits. All rights reserved.
//

#ifndef __Project__TestScene__
#define __Project__TestScene__

#import "Scene.h"

class VectorMan;

class TestScene : public Scene {
    VectorMan *vectorMan;
public:
    TestScene();
    void onEnter();
};

#endif /* defined(__Project__TestScene__) */
