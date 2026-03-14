#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;



cv::Mat copyImageFunc(cv::Mat img, cv::Mat &copyIm)
{
	copyIm = cv::Mat(cv::Size(img.cols, img.rows), CV_8UC3);
	cv::namedWindow("copying process", cv::WINDOW_NORMAL);

	for(int x = 0; x < img.cols; x++)
	{
		for(int y = 0; y < img.rows; y++)
		{
			cv::Vec3b& bgr = img.at<cv::Vec3b>(cv::Point(x, y));
			copyIm.at<cv::Vec3b>(cv::Point(x, y)) = bgr;
			cv::imshow("copying process", copyIm);
			cv::waitKey(1);
		}
	}
	return copyIm;
}


int main()


{ 
	string filePath = "C:/openCVimages/i5.jpg";
	cv::Mat img = cv::imread(filePath);
	cv::Mat copyIm;
	cv::imshow("window", copyImageFunc(img, copyIm));
	cv::waitKey();
	return 0;
}
