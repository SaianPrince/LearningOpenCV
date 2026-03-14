#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;



void readImage(string filePath)
{
	cv::Mat copyIm;
	cv::Mat img = cv::imread(filePath);
	img.copyTo(copyIm);
	cv::imshow("before",copyIm);
	cv::waitKey();

	for (int x = 0; x < copyIm.cols; x++) 
	{
		for (int y =0;y<copyIm.rows;y++)
		{
			cv::Vec3b& pixel = copyIm.at<cv::Vec3b>(cv::Point(x, y));
			if (pixel[2] == 255)
			{
				pixel[2] = 0;
			}

		}

	}
	cv::imshow("after", copyIm);
	cv::waitKey();

	return;
}


int main()


{
	string filePath = "C:/openCVimages/i3.jpg";

	readImage(filePath);
	return 0;
}
