#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;


Mat detectionFeature (Mat);

std::vector< DMatch > matcher (Mat,Mat);

std::vector<KeyPoint> getPointCle (Mat );

//Mat getHomography(Mat, Mat);

#endif // TRAITEMENT_H
