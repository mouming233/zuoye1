#include"opencv2/opencv.hpp"
using namespace cv;
using namespace std;


int main()
{

    const char filename_2[] = "zuoye.jpeg";
    vector<Mat> img_channels;
    Mat img = imread(filename_2);
    imshow ("img",img);
    Mat redminblue,blueminred,imgGray;


    split(img, img_channels);
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    Mat bluechannel = img_channels.at(0);
    Mat greenchannel = img_channels.at(1);
    Mat redchannel = img_channels.at(2);

    imshow("Gray", imgGray);
    // imshow("redchannel", redchannel);

    // imshow("bluechannel", bluechannel);

    int flag,flag_gray = 0;

    //绿色通道取反
    bitwise_not(bluechannel, bluechannel);
    Mat out,out2;
    bitwise_and(redchannel, bluechannel, redminblue);
    namedWindow("trackbar", WINDOW_AUTOSIZE);
    createTrackbar("flag", "trackbar", &flag, 255);
    createTrackbar("flag_gray", "trackbar", &flag_gray, 255);
    
    Mat out_two;
    
    //二值化
    while (true)
    {
        threshold(redminblue, out,flag, 255, THRESH_BINARY);
        threshold(imgGray, out2,flag_gray, 255, THRESH_BINARY);
        

        bitwise_and(out, out2, out_two);
    
        imshow("out_two", out_two);
        imshow("gray", out2);
        imshow("min", out);
        waitKey(1);
    }
    



    waitKey(0);

    return 0;


}