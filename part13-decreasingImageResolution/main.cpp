#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

cv::Mat scaleImage(cv::Mat image, int scaleFactor = 2)
{
	int newWidth = image.cols / scaleFactor;
	int newHeight = image.rows / scaleFactor;
	cv::Mat scaledImage(cv::Size(newWidth, newHeight), CV_8UC3);
	cv::Vec3b bgr;

	cout << endl << "The process has been started !" << endl;
	cout << "Resolution is: " << image.cols << " X " << image.rows << endl << endl;


	if(!image.data)
	{
		cout << "Error Code: 101" << endl;
		return cv::Mat::zeros(cv::Size(1, 1), CV_8UC3);
	}

	else
	{
		for (int x = 0; x < newWidth; x++)
		{
			for (int y = 0; y < newHeight; y++)
			{
				bgr = image.at<cv::Vec3b>(cv::Point(x*scaleFactor, y*scaleFactor));
				scaledImage.at<cv::Vec3b>(cv::Point(x, y)) = bgr;
			}
		}
	}
	cout << endl << "The process is complete !" << endl;
	cout << "New Resolution is: " << scaledImage.cols << " X " << scaledImage.rows << endl << endl;
	return scaledImage;
}



int main()
{
	string filePath = "C:/openCVimages/i1.jpg";
	cv::Mat originalIm = cv::imread(filePath);
	cv::imshow("window1", originalIm);
	cv::imshow("window2",scaleImage(originalIm,3));
	cv::waitKey();

}
