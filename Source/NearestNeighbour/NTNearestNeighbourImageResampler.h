//
//  NTNearestNeighbourImageResampler.hpp
//  NTImageResampler
//
//  Created by Tejus on 3/8/17.
//  Copyright © 2017 Entropy. All rights reserved.
//

#ifndef NTNearestNeighbourImageResampler_h
#define NTNearestNeighbourImageResampler_h

#include <stdio.h>

#include "NTImageResampler.h"

class NTNearestNeighbourImageResampler : public NTImageResampler {
public:
    
    NTNearestNeighbourImageResampler (float scaleFactor);
    
    NTError
    Downsample (NTImage* sourceImage,
                NTImage* resampledImage);
    
    NTError
    Upsample (NTImage* sourceImage,
              NTImage* resampledImage);
    
};

#endif /* NTNearestNeighbourImageResampler_h */
