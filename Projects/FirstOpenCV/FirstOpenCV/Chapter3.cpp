#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    string path = "Resources/test.png";
    Mat img = imread(path);
    Mat imgResize, imgCrop;

    resize(img, imgResize, Size(), 0.5, 0.5);
    Rect roi(100, 100, 300, 250);
    imgCrop = img(roi);

    imshow("Image", img);
    imshow("Image Resize", imgResize);
    imshow("Image Crop", imgCrop);

    waitKey(0);
    return 0;
}