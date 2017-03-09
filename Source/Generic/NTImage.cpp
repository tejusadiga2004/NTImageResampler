//
//  NTImage.cpp
//  NTImageResampler
//
//  Created by Tejus on 3/8/17.
//  Copyright © 2017 Entropy. All rights reserved.
//

#include "NTImage.h"
#include <assert.h>



bool NTSize::operator == (const NTSize& size)
{
    return width == size.width && height == size.height;
}

NTSize NTSize::operator * (float scale)
{
    return NTSize(width * scale, height * scale);
}

NTSize NTSize::operator / (float scale)
{
    NTSize size = NTSize();
    
    if (scale > 0) {
        size = NTSize(width / scale, height / scale);
    }
    
    return size;
}

NTImage::NTImage (uint8_t* bytes, int length, NTSize imageSize) :
_Bytes(nullptr), _Length(length), _Size(imageSize)
{
    assert(length > 0);
    
    _Bytes = new uint8_t[length];
    if (_Bytes) {
        memset(_Bytes, 0, length);
        if (bytes) {
            memcpy(_Bytes, bytes, length);
        }
    }
}

NTImage::NTImage (NTImage* image) :
NTImage(image->Bytes(), image->Length(), image->Size())
{
    
}

NTImage::~NTImage ()
{
    if (_Bytes) {
        delete _Bytes;
        _Bytes = nullptr;
    }
}
