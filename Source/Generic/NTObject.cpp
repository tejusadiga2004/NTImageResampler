//
//  NTObject.cpp
//  NTImageResampler
//
//  Created by Tejus on 3/8/17.
//  Copyright © 2017 Entropy. All rights reserved.
//

#include "NTObject.h"

NTError::NTError (int errorCode) :
NTError(errorCode, "")
{
    
}

NTError::NTError (int errorCode, std::string desc) :
errorCode(errorCode),
desription(desc)
{
    
}

NTError::NTError (NTError& error) :
NTError(error.errorCode, "error.desription")
{
    
}


NTObject::NTObject ()
: retainCount(1)
{
    
}

NTObject::~NTObject ()
{
    
}

void NTObject::Retain ()
{
    ++retainCount;
}

void NTObject::Release ()
{
    if (--retainCount <= 0) {
        delete this;
    }
}
