#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

bool draw = false;


struct imageDetails
{
	bool draw = false;
	cv::Mat image;
	string window;
	int colorTimer = 0;
	cv::Vec3b color;
	
	void increaseColorTimer()
	{
		colorTimer++;
		if (colorTimer == 3)
			colorTimer = 0;
	}

	cv::Vec3b getColor()
	{
		switch (colorTimer)
		{
		case 0:
			color = cv::Vec3b(255, 0, 0);
			break;
		case 1:
			color = cv::Vec3b(0, 255, 0);
			break;
		case 2:
			color = cv::Vec3b(0, 0, 255);
			break;
		default:
			break;
		}
		return color;
	}
};
void mouseEvent(int event, int x, int y, int flag, void* data)
{
	
	imageDetails* r = (imageDetails*)data;
	

	if(event == cv::EVENT_LBUTTONDOWN)
	{
		r->draw = true;
	}
	else if(event == cv::EVENT_RBUTTONDOWN)
	{
		r->increaseColorTimer();
	}
	else if(event == cv::EVENT_LBUTTONUP)
	{
		r->draw = false;
	}
	if(r->draw)
	{
		r->image.at<cv::Vec3b>(cv::Point(x, y)) = r->getColor();
		cv::imshow(r->window, r->image);
	}

}


void mouseSetup()
{
	imageDetails image;
	image.image = cv::Mat::zeros(cv::Size(800, 600), CV_8UC3);
	image.window = "window";
	cv::imshow(image.window, image.image);
	cv::setMouseCallback("window", mouseEvent, &image);
	cv::waitKey();
	
}


int main()
{
	string filePath = "C:/openCVimages/i1.jpg";

	mouseSetup();
	

	return 0;
}
