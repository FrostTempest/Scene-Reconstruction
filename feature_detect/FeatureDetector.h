#pragma once
#import "Image.h"

namespace SceneComps {

class FeatureDetector {

public:
    virtual void detect(Image image, std::vector<KeyPoint>) = 0;
};

}