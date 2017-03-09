//
//  NTImage.hpp
//  NTImageResampler
//
//  Created by Tejus on 3/8/17.
//  Copyright © 2017 Entropy. All rights reserved.
//

#ifndef NTImage_h
#define NTImage_h

#include "NTObject.h"
#include "NTProperty.h"

#include <iostream>

typedef struct NTSize {
    int width;
    int height;
    
    NTSize () : width(0), height(0) {}
    
    NTSize (int inWidth, int inHeight) : width(inWidth), height(inHeight) {}
    
    bool operator == (const NTSize& size);
    NTSize operator * (float scale);
    NTSize operator / (float scale);

} NTSize;

static NTSize NTSizeZero = NTSize();

class NTImage : public NTObject {

NTPropertyAssignReadOnly(NTSize, Size)

NTPropertyAssignReadOnly(int, Length)

NTPropertyReadOnly(uint8_t, Bytes)

public:
    
    NTImage (uint8_t* bytes, int length, NTSize imageSize);
    
    NTImage (NTImage* image);
    
    ~NTImage ();
};

#endif /* NTImage_hpp */
