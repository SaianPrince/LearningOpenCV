#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;

struct Values
{
	int currentMorphType = 0;
	int currentShape = 0;
	int x = 1;
	int y = 1;
};

void trackbarFunc(int position, void* userdata)
{	

}

void morphologyEX(cv::Mat img)
{
	Values* value = new Values();
	string trackbarShape = "Shape";
	string trackbarSizeX = "size X";
	string trackbarSizeY = "size Y";
	string morpTypes = "Morphology Trackbar";
	string windowTrackbar = "Trackbar";
	cv::namedWindow(windowTrackbar, cv::WINDOW_NORMAL);
	cv::createTrackbar(morpTypes, windowTrackbar, &value->currentMorphType, 6, trackbarFunc);
	cv::createTrackbar(trackbarShape, windowTrackbar, &value->currentShape, 2, trackbarFunc);
	cv::createTrackbar(trackbarSizeX, windowTrackbar, &value->x, 8, trackbarFunc);
	cv::createTrackbar(trackbarSizeY, windowTrackbar, &value->y, 8, trackbarFunc);

	cv::waitKey();
}

int main()
{
	string filePath = "C:/openCVimages/i3.jpg";
	
	cv::Mat img = cv::imread(filePath);
	cv::imshow("original", img);
	morphologyEX(img);

	return 0;
}
