//
// Created by Mrinal Rawool on 5/21/19.
//

#include "utilities.h"

void info(){
    cout << "\nDemonstration of Canny Edge Detection using OpenCV";
}

void help(int required, int actual){
    err << "\nUsage:\t cannyEdge imagefile.extension";
    if (required > actual){
        err << "\nInsufficient parameters passed. Expected "<< required << " Passed "<< actual;
    }else{
        err << "\nToo many parameters passed. Expected "<< required << " Passed "<< actual;
    }

}

void display(string windowName, Mat& image, bool save){
    imshow(windowName, image);
    if (save){
        string imageName = windowName + ".jpg";
        imwrite(imageName, image);
    }
}