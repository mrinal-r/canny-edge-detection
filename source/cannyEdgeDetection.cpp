//
// Created by Mrinal Rawool on 4/23/19.
//

#include "cannyEdgeDetection.h"


Mat cannyEdgedetector(Mat& image){

    Mat output;

    // -- gaussian blurring with 3X3 -- //
    GaussianBlur(image, image, Size(5, 5), 0, 0, BORDER_DEFAULT);

    // -- call canny edge -- //
    double minThreshold = 50.0;  // works well between 35 and 65 as the lower limit
    //double maxThreshold = 180;
    int sobelKernelSize = 3;
    float ratio = 3.0;
    Canny(image, output, minThreshold, (ratio * minThreshold), sobelKernelSize);

    return output;

}

Mat superimpose(Mat& original, Mat& canny){

    // -- create array of matrices -- //
    Mat matArray[3];

    // -- initialize -- //
    int h = original.rows;
    int w = original.cols;

    matArray[0]= Mat(h,w,CV_8UC1, Scalar(0));
    matArray[1]= Mat(h,w,CV_8UC1, Scalar(0));
    matArray[2]= canny.clone();

    Mat colorEdge;
    // -- creating a colored version of edges -- /
    merge(matArray,3, colorEdge);

    // -- creating color version of original image -- /
    Mat colorImage;
    cv::cvtColor(original, colorImage, CV_GRAY2BGR);

    // -- final output -- //
    Mat output = colorImage.clone();

    //addWeighted(colorImage, 0.5, colorEdge, 0.5, 0, output);
    for(int row=0; row<h; row++){
        for(int col=0; col<w; col++){
            if((int)canny.at<uchar>(row,col)>0){
                output.at<Vec3b>(row,col)= colorEdge.at<Vec3b>(row, col);
            }
        }
    }
    return output;
}

/*
 * C++: void Canny(InputArray image, OutputArray edges, double threshold1, double threshold2,
 * int apertureSize=3, bool L2gradient=false )
 * Parameters:
 * image – single-channel 8-bit input image.
 * edges – output edge map; it has the same size and type as image .
 * threshold1 – first threshold for the hysteresis procedure.
 * threshold2 – second threshold for the hysteresis procedure.
 * apertureSize – aperture size for the Sobel() operator.
 * L2gradient – a flag, indicating whether a more accurate
 * L_2 norm  =\sqrt{(dI/dx)^2 + (dI/dy)^2} should be used to calculate the image gradient
 * magnitude ( L2gradient=true ), or whether the default  L_1 norm  =|dI/dx|+|dI/dy| is
 * enough ( L2gradient=false ).
 * The function finds edges in the input image image and marks them in the output map edges
 * using the Canny algorithm. The smallest value between threshold1 and threshold2 is used for
 * edge linking. The largest value is used to find initial segments of strong edges.
 * See http://en.wikipedia.org/wiki/Canny_edge_detector
 */