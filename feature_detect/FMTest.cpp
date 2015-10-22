#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "FeatureDetectorSIFT.h"
#include "KeyPointDescriptor.h"
#include "Image.h"


using namespace cv;
using namespace cv::xfeatures2d;
using namespace SceneComps;

int main( int argc, char** argv ) {

	if (argc != 3) { 
		std::cout << "Must provide filepath argument.\n";
		return -1; 
	}

	// Create image
	std::string filepath1 = argv[1];
	Image image1 = Image(filepath1);
    std::string filepath2 = argv[2];
	Image image2 = Image(filepath2);
    
    // Detect keypoints
    FeatureDetectorSIFT siftDetector = FeatureDetectorSIFT();
    std::vector<KeypointDescriptor> keypoints1 = siftDetector.detect(image1);
    std::vector<KeypointDescriptor> keypoints2 = siftDetector.detect(image2);

    // Convert descriptors back to cv keypoints :(
    std::vector<KeyPoint> sift_keypoints1(keypoints1.begin(), keypoints1.end());
    std::vector<KeyPoint> sift_keypoints2(keypoints2.begin(), keypoints2.end());

    //STUFF FROM THE OPEN CV EXAMPLE BELOW
    // https://github.com/npinto/opencv/blob/master/samples/cpp/matcher_simple.cpp
    cv::Ptr<Feature2D> f2d = xfeatures2d::SIFT::create();
    
    //SiftDescriptorExtractor extractor;
    Mat descriptors1, descriptors2; 
    f2d->compute(image1.matrix, sift_keypoints1, descriptors1);
    f2d->compute(image2.matrix, sift_keypoints2, descriptors2);
    
    BFMatcher matcher;
    std::vector<DMatch> matches;
    matcher.match(descriptors1, descriptors2, matches);
    
    // drawing the results
    namedWindow("matches", 1);
    Mat img_matches;
    drawMatches(image1.matrix, sift_keypoints1, image2.matrix, sift_keypoints2, matches, img_matches);
    imshow("matches", img_matches);

	std::cout << "^C to exit.\n";
	for(;;){
        waitKey(0);
    }

	return 0;
}