#include <opencv2/opencv.hpp>
#include <iostream>
#include "Trackbar.h"

using namespace std;

void colorSpaces(cv::Mat img)
{
	cv::Mat convertImage;
	cv::cvtColor(img, convertImage, cv::COLOR_BGR2GRAY);
	cv::imshow("BGR2GRAY",convertImage);
	cv::cvtColor(img, convertImage, cv::COLOR_BGR2HLS);
	cv::imshow("BGR2HLS", convertImage);
	cv::cvtColor(img, convertImage, cv::COLOR_BGR2HSV);
	cv::imshow("BGR2HSV", convertImage);
	cv::cvtColor(img, convertImage, cv::COLOR_BGR2Lab);
	cv::imshow("BGR2Lab", convertImage);

	cv::waitKey();
}


int main()
{
	string filePath = "C:/openCVimages/i1.jpg";

	cv::Mat main = cv::imread(filePath);
	cv::Mat resized;
	cv::resize(main, resized, cv::Size(426,240));
	cv::imshow("window", resized);
	colorSpaces(resized);
	
	return 0;
}
