#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

void createImageScalar(int width, int length,int blue, int green,int red)
{
	cv::Mat img(length, width, CV_8UC3, cv::Scalar(blue, green, red));
	cv::imshow("window", img);
	cv::waitKey();
}

int main()
{
	
	createImageScalar(800, 600, 255, 0, 0);
	return 0;

}
