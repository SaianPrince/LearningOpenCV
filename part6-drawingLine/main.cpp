#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

cv::Mat draw(string filePath, int x1, int y1, int x2, int y2,
			int blue, int green, int red,int thickness) 
{
	cv::Mat image, newImage;
	image = cv::imread(filePath);
	image.copyTo(newImage);
	cv::line(newImage, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(blue, green, red), 
			thickness);
	return newImage;
}

int main()


{
	string filePath = "C:/openCVimages/i1.jpg";

	cv::imshow("window", draw(filePath, 500, 500, 100, 150,0,0,255,5));
	cv::waitKey();
	cv::destroyAllWindows();
	


	return 0;
}
