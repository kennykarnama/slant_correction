#ifndef SLANT_H
#define SLANT_H

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <map>
#include "descriptive_stats.h"


#define PI 3.14159265

 class Slant
 {
 public:
 	Slant();
 	
 	~Slant();

 	double angle(cv::Mat,double,double,double);



 	cv::Mat shear(cv::Mat,double);

 	
 };
#endif