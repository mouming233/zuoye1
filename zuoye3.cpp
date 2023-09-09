#include"opencv2/opencv.hpp"
#include<string>
using namespace cv;
using namespace std;


int main()
{
    const char filename_1[] = "步兵.mp4";
    const char filename_2[] = "zuoye.jpeg";

    cv::VideoCapture capture(filename_1);

    if (!capture.isOpened())
    {
        std::cout << "fail to open video" << std::endl;
        return -1;
    }

    cv::Mat frame;

    for (int i = 0; i < capture.get(7); i++)
    {
        capture >> frame;
        putText(frame, to_string(i), Point(50, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 2, 8);
        imshow("frame", frame);
        
        if(i==1905)
        {
            imwrite(filename_2, frame);
        }
        int c;
        while (true) {
            c = waitKey(500);
            // cout << c << endl;
            if (c == 113)
                break;
	    }
    }
    



    return 0;
}