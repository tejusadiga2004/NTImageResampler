//
//  NTNearestNeighbourImageResampler.cpp
//  NTImageResampler
//
//  Created by Tejus on 3/8/17.
//  Copyright © 2017 Entropy. All rights reserved.
//

#include "NTNearestNeighbourImageResampler.h"

NTNearestNeighbourImageResampler::NTNearestNeighbourImageResampler (float scaleFactor)
: NTImageResampler(scaleFactor)
{
    
}

NTError
NTNearestNeighbourImageResampler::Downsample (NTImage* sourceImage,
                                              NTImage* resampledImage)
{
    NTError result = NTNoError;
    
    NTSize sourceSize = sourceImage->Size();
    NTSize destSize = resampledImage->Size();
    
    uint8_t* srcImg = sourceImage->Bytes();
    uint8_t* destImg = resampledImage->Bytes();
    
    int srcPerDestPixel = 1 / scaleFactor;
    
    for (int row = 0; row < destSize.height; row++) {
        uint8_t* srcRow = srcImg + (int)(row * sourceSize.width * srcPerDestPixel);
        uint8_t* destRow = destImg + (int)(row * destSize.width);

        for (int col = 0; col < destSize.width; col++) {
            *destRow++ = *srcRow;
            srcRow += srcPerDestPixel;
        }
    }
    
    return result;
}

NTError
NTNearestNeighbourImageResampler::Upsample (NTImage* sourceImage,
                                            NTImage* resampledImage)
{
    NTError result = NTNoError;
    
    NTSize sourceSize = sourceImage->Size();
    NTSize destSize = resampledImage->Size();
    
    uint8_t* srcImg = sourceImage->Bytes();
    uint8_t* destImg = resampledImage->Bytes();
    
    int srcPerDestPixel = 1 / scaleFactor;
    
    for (int row = 0; row < destSize.height; row++) {
        uint8_t* srcRow = srcImg + (int)(row * sourceSize.width * srcPerDestPixel);
        uint8_t* destRow = destImg + (int)(row * destSize.width);
        
        for (int col = 0; col < destSize.width; col++) {
            *destRow++ = *srcRow;
            srcRow += srcPerDestPixel;
        }
    }
    
    return result;
}
