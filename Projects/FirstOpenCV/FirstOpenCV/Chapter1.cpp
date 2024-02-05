#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*
int main()
{
    string path = "Resources/test_video.mp4";
    VideoCapture cap(path);
    Mat img;
    while (cap.read(img)) {
        imshow("Image", img);
        waitKey(1);
    }
    cap.release();//Releasing the buffer memory//
    return 0;
}
*/

int main()
{
    VideoCapture cap(0);
    Mat img;
    while (cap.read(img)) {
        imshow("Image", img);
        char c = (char)waitKey(1);
        if (c == 27) { //If 'Esc' is entered break the loop//
            break;
        }
    }
    cap.release();//Releasing the buffer memory//
    return 0;
}