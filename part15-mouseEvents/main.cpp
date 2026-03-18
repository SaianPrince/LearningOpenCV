#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

void mouseEvent(int event, int x, int y, int flags, void* userdata)
{
	if (event == cv::EVENT_LBUTTONDOWN)
		cout << "mouse was clicked" << endl;

	else if (event == cv::EVENT_LBUTTONUP)
		cout << "mouse is free now" << endl;

	else if (event == cv::EVENT_RBUTTONDOWN)
		cout << "r_mouse was clicked" << endl;

	else if (event == cv::EVENT_RBUTTONUP)
		cout << "r_mouse is free now" << endl;

	else if (event == cv::EVENT_MOUSEWHEEL)
	{
		cout << "mouse wheel was pressed" << endl;
		cout << flags << endl;
	}
	else if (event == cv::EVENT_MOUSEMOVE)
	{
		cout << "mouse is moving" << endl;
		cout << "x: " << x << ", y: " << y << endl;
	}
}

void mouseSetup()
{
	cv::Mat img = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);
	cv::namedWindow("window");
	cv::setMouseCallback("window", mouseEvent);
	cv::moveWindow("window", 400, 200);
	cv::imshow("window", img);
	cv::waitKey();
}


int main()
{
	mouseSetup();
	return 0;
}
