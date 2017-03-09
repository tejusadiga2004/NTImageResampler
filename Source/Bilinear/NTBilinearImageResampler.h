//
//  NTBilinearResampler.hpp
//  NTImageResampler
//
//  Created by Tejus on 3/9/17.
//  Copyright © 2017 Entropy. All rights reserved.
//

#ifndef NTBilinearResampler_h
#define NTBilinearResampler_h

#include "NTImageResampler.h"

class NTBilinearImageResampler : public NTImageResampler {
public:
    
    NTBilinearImageResampler (float scaleFactor);
    
    NTError
    Downsample (NTImage* sourceImage,
                NTImage* resampledImage);
    
    NTError
    Upsample (NTImage* sourceImage,
              NTImage* resampledImage);
};

#endif /* NTBilinearResampler_h */
