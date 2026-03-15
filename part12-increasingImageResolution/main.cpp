#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

cv::Mat scaleImage(cv::Mat image, int scaleFactor = 2)
{
	int newWidth = image.cols * scaleFactor;
	int newHeight = image.rows * scaleFactor;

	cv::Mat empty(cv::Size(newWidth,newHeight),CV_8UC3);
	cv::Vec3b bgr;


	cout << endl << "The process has been started !" << endl;
	cout << "Resolution is: " << image.cols << " X " << image.rows << endl << endl;
	for (int x = 0; x < image.cols; x++) 
	{
		for (int y = 0; y < image.rows; y++) 
		{
			bgr = image.at<cv::Vec3b>(cv::Point(x, y));
			int beginningX = x * scaleFactor;
			int beginningY = y * scaleFactor;
			int endX = beginningX + scaleFactor;
			int endY = beginningY + scaleFactor;
			for(int i = beginningX; i < endX; i++)
			{
				for(int j = beginningY; j < endY; j++)
				{
					empty.at<cv::Vec3b>(cv::Point(i, j)) = bgr;
				}
			}
		}
	}
	cout << endl <<"The process is complete !" << endl;
	cout << "New Resolution is: " << empty.cols << " X " << empty.rows << endl << endl;
	return empty;
}


int main()
{
	string filePath = "C:/openCVimages/i5.jpg";
	cv::Mat originalIm = cv::imread(filePath);
	cv::imshow("window1", originalIm);
	cv::imshow("window2",scaleImage(originalIm,5));
	cv::waitKey();

}
