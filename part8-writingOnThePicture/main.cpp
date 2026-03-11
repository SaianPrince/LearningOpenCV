#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

cv::Mat text(string filePath, string text,int x,int y,int fontsize,int thickness,bool mirroring = false) 
{
	cv::Mat img, newImg;
	img = cv::imread(filePath);
	img.copyTo(newImg);
	cv::putText(newImg, text, cv::Point(x, y+5), cv::FONT_HERSHEY_COMPLEX, 
			   fontsize, cv::Scalar(255, 0, 0), thickness,8,mirroring);
	cv::putText(newImg, text, cv::Point(x, y), cv::FONT_HERSHEY_COMPLEX,
		fontsize, cv::Scalar(255, 0, 0), thickness, 8, false);
	return newImg;
}



int main()


{
	string filePath = "C:/openCVimages/i1.jpg";

	cv::imshow("window", text(filePath, "OpenCV C++", 200, 200, 5,5,true));
	cv::waitKey();

	return 0;
}
