#include "cannyEdgeDetection.h"
#include "utilities.h"

ostringstream err;

int main(int argc, char* argv[]) {

    info();

    try{

        if (argc != 2){
            help(2,argc);
            throw err.str();
        }

        string imageName = argv[1];
        string filename = "../../data/"+imageName;
        cout << "\nProcessing file " << filename << "\n";

        Mat image = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);

        Mat edgy = cannyEdgedetector(image);

        Mat combined = superimpose(image, edgy);

        display("image", image);
        display("edges", edgy, true);
        display("combined", combined, true);
        waitKey();

        cvDestroyAllWindows();

    }catch(string& errorMessage){
        cout << "\nError in MAIN: "<< errorMessage;
    }

    return 0;
}