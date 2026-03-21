#include <opencv2/opencv.hpp>
#include <iostream>
#include "Trackbar.h"

using namespace std;


void trackbarFunc(int position, void* data)
{
	TrackbarClass* trackbar = (TrackbarClass*)data;
	cout << "trackbar current value : " << *trackbar->getCurrent() << endl;

}

void trackbarDemo()
{
	string trackbarName = "trackbar";
	string winName = "window";
	cv::namedWindow(winName, cv::WINDOW_AUTOSIZE);
	TrackbarClass* tb = new TrackbarClass;
	tb->setMax(100);
	cv::createTrackbar(trackbarName, winName, tb->getCurrent(), *tb->getMax(), trackbarFunc, tb);
	cv::setTrackbarMin(trackbarName, winName, 30);
	cv::setTrackbarMax(trackbarName, winName, 150);
	cv::setTrackbarPos(trackbarName, winName, 44);
	cv::waitKey();
}

int main()
{
	string filePath = "C:/openCVimages/i1.jpg";

	trackbarDemo();

	return 0;
}
