//
//  KeyboardListener.h
//  KeyboardHandlerTestCPP
//
//  Created by Colden Prime on 12/11/12.
//  Copyright (c) 2012 Colden Prime. All rights reserved.
//

#ifndef KeyboardHandlerTestCPP_KeyboardListener_h
#define KeyboardHandlerTestCPP_KeyboardListener_h

class KeyboardListener {
public:
    virtual void KeyPressed(void* handler, char key, bool down) = 0;
    ~KeyboardListener() {};
};

#endif
