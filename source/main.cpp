#include "slant.h"

void displayImage(std::string namaWindow, int jenisWindow, cv::Mat gambarnya);


int main(int argc, char const *argv[])
{
	/* code */

	cv::Mat img = cv::imread(argv[1],CV_LOAD_IMAGE_ANYDEPTH );

	std::string nama_file(argv[2]);


	cv::threshold(img, img, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

	Slant slant;

	double shear_angle = slant.angle(img,-45.0,45.0,1.0);

	//std::cout <<shear_angle << std::endl;

	cv::bitwise_not(img,img);

	cv::Mat hasil = slant.shear(img,shear_angle);

	cv::bitwise_not(hasil,hasil); 

	// displayImage("original",CV_WINDOW_KEEPRATIO,img);

	// displayImage("gambar",CV_WINDOW_KEEPRATIO,hasil);

	//Slant slant;


	bool status_tulis = cv::imwrite(nama_file+".png",hasil);

	std::string output = "";

	if(status_tulis){
		output = nama_file+".png"+";"+std::to_string(shear_angle);
	}
	else{
		output = "error";
	}

	std::cout << output << std::endl;


	return 0;
}

void displayImage(std::string namaWindow, int jenisWindow, cv::Mat gambarnya){
	
	cv::namedWindow(namaWindow,jenisWindow);

	cv::imshow(namaWindow,gambarnya);

	cv::waitKey(0);
}
