#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

void drawRectangle(cv::Mat &img,int x1,int y1,int x2,int y2)
{
	cv::rectangle(img, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(0, 255, 0), 5);
}

void drawRectangle(cv::Mat &img, int x, int y, int width, int height,int thickness)
{
	cv::Rect area(x, y, width, height);
	cv::rectangle(img, area, cv::Scalar(255, 0, 150));
}



int main()


{
	string filePath = "C:/openCVimages/i1.jpg";
	cv::Mat img = cv::imread(filePath);

	drawRectangle(img, 200, 200, 400, 400);
	drawRectangle(img, 100, 100, 300, 300, 15);

	cv::imshow("window",img);
	cv::imshow("window", img);
	cv::waitKey();

	return 0;
}
