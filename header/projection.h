#ifndef PROJECTION_H
#define PROJECTION_H

#include <opencv2/opencv.hpp>

#include <string>

#include <vector>


	
	class Projection
	{
	public:
		Projection();
		~Projection();

		std::vector<int> projectVertical(cv::Mat);

		cv::Mat getImgVerProj(std::vector<int>, cv::Mat);

		std::vector<int> projectHorizontal(cv::Mat);

		cv::Mat getImgHorProj (std::vector<int>, cv::Mat);

	
		/* data */
	};
#endif