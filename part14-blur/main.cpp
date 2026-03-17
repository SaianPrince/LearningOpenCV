#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;


cv::Mat blur(cv::Mat image, int neighborhood = 1)
{
	cv::Mat blurIm = cv::Mat::zeros(cv::Size(image.cols, image.rows), CV_8UC3);
	int blue = 0, green = 0, red = 0, counter = 0;
	

	for(int x = 0; x < image.cols; x++)
	{
		for(int y = 0; y < image.rows; y++)
		{
			
			for(int startX = x - neighborhood; startX < x + neighborhood; startX++)
			{
				for(int startY = y - neighborhood; startY < y + neighborhood; startY++)
				{
					if(startX >= 0 && startY >= 0 && startX < image.cols && startY < image.rows)
					{
						blue += image.at<cv::Vec3b>(cv::Point(startX, startY))[0];
						green += image.at<cv::Vec3b>(cv::Point(startX, startY))[1];
						red += image.at<cv::Vec3b>(cv::Point(startX, startY))[2];

						counter++;
					}
				}
			}

			blue = blue / counter;
			green = green / counter;
			red = red / counter;

			blurIm.at<cv::Vec3b>(cv::Point(x, y))[0] = blue;
			blurIm.at<cv::Vec3b>(cv::Point(x, y))[1] = green;
			blurIm.at<cv::Vec3b>(cv::Point(x, y))[2] = red;

			blue = 0, green = 0, red = 0, counter = 0;

		}
	}
	return blurIm;
}


int main()
{
	string filePath = "C:/openCVimages/i1.jpg";
	cv::Mat image = cv::imread(filePath);

	cv::namedWindow("before", cv::WINDOW_NORMAL);
	cv::namedWindow("after", cv::WINDOW_NORMAL);

	cv::imshow("before", image);
	cv::imshow("after",blur(image,10));

	cv::waitKey();

}
