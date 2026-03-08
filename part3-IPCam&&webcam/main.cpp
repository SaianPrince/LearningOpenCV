#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

void webcam(int ch)
{
	cv::VideoCapture video;
	if (video.open(ch))
	{
		cout << "\nThe webcam was opened successfully ! \n" << endl;
		cv::namedWindow("window", cv::WINDOW_NORMAL);
		cv::Mat img;


		while (video.read(img))
		{
			int fps = video.get(cv::CAP_PROP_FPS);
			if (fps <= 0) fps = 30;
			int timePerFrame = 1000 / fps;


			cv::imshow("window", img);
			int key = cv::waitKey(timePerFrame);
			if (key == 27)
			{
				break;
			}

		}
		cout << "\nThe webcam was closed ! \n" << endl;
		cv::destroyWindow("window");
	}

	else
	{
		cout << "\nChannel is: " << ch << " The webcam was not opened successfully !\n" << endl;
		return;
	}
	return;
}

void webcam(string ip)
{
	cv::VideoCapture video;
	if (video.open(ip))
	{
		cout << "\nThe webcam was opened successfully ! \n" << endl;
		cv::namedWindow("window", cv::WINDOW_NORMAL);
		cv::Mat img;
		

		while (video.read(img))
		{
			int fps = video.get(cv::CAP_PROP_FPS);
			if (fps <= 0) fps = 30;
			int timePerFrame = 1000 / fps;

			
			cv::imshow("window", img);
			int key = cv::waitKey(timePerFrame);
			if (key == 27)
			{
				break;
			}

		}
		cout << "\nThe webcam was closed ! \n" << endl;
		cv::destroyWindow("window");
	}

	else
	{
		cout << "\nIP address is: " << ip << " The webcam was not opened successfully !\n" << endl;
		return;
	}
	return;
}

int main()
{
	webcam(0);

	return 0;

}
