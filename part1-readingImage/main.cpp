#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;


void readImage(string filePath)
{
	cv::Mat image;

	image = cv::imread(filePath);

	if(image.empty())
	{
		cout << "The image was not found ! Specified file path: " << filePath << endl;
		// the image was read

	}
	
	else
	{
		cout << "The image was found successfully! " << endl;
		cv::namedWindow("window"); // the window was created
		cv::imshow("window", image);
		cv::waitKey(); 
		cv::destroyWindow("window");
	}

}
int main()
{
	readImage("C:/openCVimages/i1.jpg");

}
