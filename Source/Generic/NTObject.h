//
//  NTObject.hpp
//  NTImageResampler
//
//  Created by Tejus on 3/8/17.
//  Copyright © 2017 Entropy. All rights reserved.
//

#ifndef NTObject_h
#define NTObject_h

#include <iostream>

#define NTRelease(ptr) \
if (ptr) { \
    ptr->Release(); \
    ptr = nullptr; \
}

typedef struct NTError {
    int         errorCode;
    std::string desription;
    
    NTError (int errorCode);
    
    NTError (int errorCode, std::string desc);
    
    NTError (NTError& error);
    
} NTError;

static NTError NTNoError = {0, ""};

class NTObject {
public:
    
    NTObject ();
    
    ~NTObject ();
    
    void Retain ();
    
    void Release ();
    
private:
    
    int retainCount;
};

#endif /* NTObject_hpp */
