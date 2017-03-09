//
//  NTImageResampler.hpp
//  NTImageResampler
//
//  Created by Tejus on 3/8/17.
//  Copyright © 2017 Entropy. All rights reserved.
//

#ifndef NTImageResampler_h
#define NTImageResampler_h

#include <iostream>

#include "NTImage.h"

enum NTImageResamplerErrorCodes {
    NTResamplerError_InsufficientMemory = -1000,
    NTResamplerError_InvalidSize
};

typedef enum NTImageResamplerAlgo {
    NTImageResamplerAlgo_NearestNeighbour,
    NTImageResamplerAlgo_Bilinear,
    NTImageResamplerAlgo_Bicubic,
    NTImageResamplerAlgo_Lanczos
} NTImageResamplerAlgo;

class NTImageResampler : public NTObject {
public:
    
    static NTImageResampler*
    Create (NTImageResamplerAlgo resamplerAlgorithm,
                                     float scaleFactor);
    
    virtual NTError
    Resample (NTImage* sourceImage,
              NTImage* resampledImage);
    
    virtual
    ~NTImageResampler ();
    
protected:
    
    NTImageResampler (float scaleFactor);
    
    float scaleFactor;
    
    virtual NTError
    Downsample (NTImage* sourceImage,
                NTImage* resampledImage) = 0;
    
    virtual NTError
    Upsample (NTImage* sourceImage,
              NTImage* resampledImage) = 0;
};

#endif /* NTImageResampler_hpp */
