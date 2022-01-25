#include <stdio.h>
#include <opencv2/opencv.hpp>


using namespace cv;
int main(int argc, char** argv )
{
    Mat loadedImage;
    loadedImage = imread( "../res/img/plate1.jpg", 1 );
    if ( !loadedImage.data )
    {
        printf("No image data \n");
        return -1;
    }

    // Creates display and shows image
    namedWindow("Plate Recognition", WINDOW_AUTOSIZE );
    imshow("Plate Recognition", loadedImage);
    waitKey(0);

    // Turn image to gray
    Mat greyImage;
    cv::cvtColor(loadedImage, greyImage, cv::COLOR_BGR2GRAY);

    // Shows grey image
    imshow("Plate Recognition", greyImage);
    waitKey(0);

    Mat bilatFilter;
    cv::bilateralFilter(greyImage, bilatFilter,11, 17, 17);

    // Shows bilateral filter
    imshow("Plate Recognition", bilatFilter);
    waitKey(0);

    // Apply Edge detect Canny filter
    Mat cannyEdges;
    cv::Canny(bilatFilter, cannyEdges, 30, 200);

    // Shows Canny filter
    imshow("Plate Recognition", cannyEdges);
    waitKey(0);

    return 0;
}