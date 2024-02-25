#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    string path = "Resources/cards.jpg";
    Mat img = imread(path);
    Mat imgWarp;

    Point2f src[4] = { {527, 143}, {771, 190}, {405, 395}, {674, 457} };
    Point2f dst[4] = { {0.0f, 0.0f}, {250, 0.0f}, {0.0f, 350}, {250, 350} };

    Mat matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix, Point(250, 350));

    for (int i = 0; i < 4; i++) {
        circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
    }

    imshow("Image", img);
    imshow("Image Warp", imgWarp);
    waitKey(0);
    return 0;
}