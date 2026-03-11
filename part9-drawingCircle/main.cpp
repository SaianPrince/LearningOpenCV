#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

cv::Mat drawCircle(string filePath, int x, int y,int radius = 50,int b = 0, int g = 0,int r = 0,
				   int thickness = 10)
{
	cv::Mat img = cv::imread(filePath);
	cv::Scalar color(b, g, r);
	cv::circle(img, cv::Point(x, y), radius, color, thickness);
	return img;
}


int main()


{
	string filePath = "C:/openCVimages/i1.jpg";

	cv::imshow("window", drawCircle(filePath,200,200,100,128,0,128,15));
	cv::waitKey();

	return 0;
}
