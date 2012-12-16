//
//  KeyboardListener.h
//  KeyboardHandlerTestCPP
//
//  Created by Glenn R. Martin on 12/11/12.
//  Copyright (c) 2012 Glenn R. Martin. All rights reserved.
//

#ifndef KeyboardHandlerTestCPP_KeyboardListener_h
#define KeyboardHandlerTestCPP_KeyboardListener_h

class KeyboardListener {
public:
    virtual void KeyPressed(void* handler, char key) = 0;
    ~KeyboardListener() {};
};

#endif
