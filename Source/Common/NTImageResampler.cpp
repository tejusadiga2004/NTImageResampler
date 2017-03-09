//
//  NTImageResampler.cpp
//  NTImageResampler
//
//  Created by Tejus on 3/8/17.
//  Copyright © 2017 Entropy. All rights reserved.
//

#include <assert.h>

#include "NTImageResampler.h"

NTImageResampler*
NTImageResampler::Create (NTImageResamplerAlgo resamplerAlgorithm,
                                            float scaleFactor)
{
    NTImageResampler* resampler = nullptr;
    
    return resampler;
}

NTImageResampler::~NTImageResampler ()
{
    
}

NTImageResampler::NTImageResampler (float scaleFactor)
: scaleFactor(scaleFactor)
{
    
}

NTError
NTImageResampler::Resample (NTImage* sourceImage,
                            NTImage* resampledImage)
{
    NTError error = NTNoError;
    
    if (resampledImage->Size() == sourceImage->Size() * scaleFactor) {
        
        if (this->scaleFactor < 1.0) {
            error = this->Downsample(sourceImage, resampledImage);
        } else {
            error = this->Upsample(sourceImage, resampledImage);
        }
    } else {
        error = NTError(NTResamplerError_InvalidSize,
                        "Size of resampled image should be scalefactor times source image");
    }

    return error;
}
