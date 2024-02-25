#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    string path = "Resources/lambo.png";
    Mat img = imread(path);
    Mat imgHSV, mask;

    cvtColor(img, imgHSV, COLOR_BGR2HSV);
    inRange(imgHSV, Scalar(0, 110, 153), Scalar(19, 240, 255), mask);

    imshow("Image", img);
    imshow("Image HSV", imgHSV);
    imshow("Mask", mask);
    waitKey(0);
    return 0;
}