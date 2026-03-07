#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;


void videoReading(string filePath)
{
	cv::VideoCapture video;
	video.open(filePath);

	if(video.isOpened())
	{
		cout << "\n The video was opened successfully! " << endl;
		cv::Mat img;
		cv::namedWindow("window");

		int fps = 30;	// my video has 30 fps
		int timePerFrame = 1000 / fps;
		int key = 0;

		while(video.read(img))
		{
			cv::imshow("window", img);
			key = cv::waitKey(timePerFrame);
			
			if (key == 27)
			{
				cout << "\nThe video was closed!\n" << endl;// The window will close 
				break;										// when you press ESC
			}
			else if(key == 43)
			{
				fps += 20;		// Fps will be increased if you press the "+" key
			}
			else if (key == 45)
			{
				if(fps != 20)	// Fps will be decreased if you press the "-" key
					fps -= 20;
			}
			int timePerFrame = 1000 / fps;
			cout << "FPS: " << fps << endl;
		}
		cv::destroyWindow("window");
	}

	else 
	{
		cout << "\n The video wasn't opened successsfully. The file path of video: " 
			 << filePath << endl;
	}
}

int main()
{
	videoReading("C:/openCVimages/openCVideos/bearMeme.mp4");

}
