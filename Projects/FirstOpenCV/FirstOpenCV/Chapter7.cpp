#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void getContours(Mat dil, Mat img) {
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(dil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRects(contours.size());

    for (int i = 0; i < contours.size(); i++) {
        float area = contourArea(contours[i]);
        cout << area << endl;
        string objType = "";

        if (area >= 1000) {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02f * peri, true);
            cout << conPoly[i].size() << endl;
            boundRects[i] = boundingRect(conPoly[i]);

            int objCor = conPoly[i].size();
            if (objCor == 3) {
                objType = "Triangle";
            }
            else if (objCor == 4) {
                float aspRatio = (float)boundRects[i].width / boundRects[i].height;
                cout << aspRatio << endl;
                if (aspRatio > 0.95f && aspRatio < 1.05f) {
                    objType = "Square";
                }
                else
                    objType = "Rectangle";
            }
            else if (objCor > 4) {
                objType = "Circle";
            }
            else
                objType = "Error";

            drawContours(img, conPoly, i, Scalar(255, 0, 255), 2); // giving index as -1 will draw all without need to loop
            rectangle(img, boundRects[i].tl(), boundRects[i].br(), Scalar(0, 255, 0), 3);
            putText(img, objType, { boundRects[i].x, boundRects[i].y - 3 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
        }
    }
}

int main()
{
    string path = "Resources/shapes.png";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDil;

    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
    Canny(imgBlur, imgCanny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDil, kernel);

    getContours(imgDil, img);
    
    imshow("Image", img);

    waitKey(0);
    return 0;
}