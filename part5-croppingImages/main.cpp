#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;


cv::Mat cropImage(string filePath,int x, int y, int width, int height)
{
	cv::Mat image;
	cv::Mat croppedIm;
	image = cv::imread(filePath);
	cv::namedWindow("window1");
	cv::imshow("window1", image);
	cv::waitKey();
	image.copyTo(croppedIm);
	croppedIm = cv::Mat(croppedIm, cv::Rect(x, y, width, height));
	return croppedIm;

}

int main()
{
	cv::imshow("window2", cropImage("C:/openCVimages/i1.jpg",0,0,200,300));
	cv::waitKey();
	return 0;
}
