#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;


void colorChannels(cv::Mat img)
{
	vector<cv::Mat> channels;
	cv::split(img, channels);

	for(int i = 0; i < channels.size(); i++)
	{
		cv::imshow(to_string(i), channels[i]);
	}
	cv::waitKey();
	cv::destroyAllWindows();
}

int main()
{
	string filePath = "C:/openCVimages/i3.jpg";
	cv::Mat image = cv::imread(filePath);
	cv::Mat resized;
	cv::resize(image, resized, cv::Size(200, 200));
	colorChannels(resized);
	
	
	return 0;
}
