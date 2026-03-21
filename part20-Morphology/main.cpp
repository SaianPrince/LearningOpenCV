#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;

void morphologyEX(cv::Mat img)
{
	cv::Mat newImg;
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::morphologyEx(img, newImg, cv::MORPH_ERODE, kernel, cv::Point(-1, -1));
	cv::imshow("new", newImg);
	cv::waitKey();
}

int main()
{
	string filePath = "C:/openCVimages/i3.jpg";
	
	cv::Mat img = cv::imread(filePath);
	cv::imshow("original", img);
	morphologyEX(img);

	return 0;
}
