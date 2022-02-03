/*------------------------------------------------------------------------------------------
    * This code will process only .jpg and .png extensions as tested
    * Importing bare minimum libraries required to display face-detection 
------------------------------------------------------------------------------------------*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\objdetect\objdetect.hpp>

/*---------------------------------------------------------------------------------------
    * Using namespace directive to import and invoke functions from
    * the standard C++ library and OpenCV library
-----------------------------------------------------------------------------------------*/

using namespace std;
using namespace cv;

/*---------------------------------------------------------------------------------------
    * The following code uses pre-trained "Haar feature-based" cascade classifiers
    * to detect objects, in this case they are : faces and eyes in an image. 
    * A cv::CascadeClassifier is created,
    * the necessary XML file is loaded using the cv::CascadeClassifier::load method.
    * Detection is done using cv::CascadeClassifier::detectMultiScale method,
    * which returns boundary rectangles for the detected faces or eyes.
-----------------------------------------------------------------------------------------*/

int main(void) {
    /*---------------------------------------------------------------------------------------
        * Creating a faceDetection object from the CascadeCalssifier class
        * The file required here is a Haar-Cascade template provided by OpenCV
    -----------------------------------------------------------------------------------------*/

    CascadeClassifier faceDetection;

    // Windows requires a "\\" directory structure change to "\" for Unix based/Linux 
    if (!faceDetection.load("C:\\Users\\user\\Downloads\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml")) {
        
        // If file is absent at the directory or could not be loaded
        cout << "\n XML File not found";
        exit(0);

        /*---------------------------------------------------------------------------------------
            * The input path is limited to 128 characters
            * Storing the path in input_path variable to pass as a parameter
            * Mat is an image container which stores the image as a matrix
            * Mat class helps automatically allocate memory for the object
        -----------------------------------------------------------------------------------------*/

        char input_path[128];
        cout << "\n Enter path of image : ";
        
        cin.getline(input_path, 128);
        Mat img = imread(input_path, IMREAD_UNCHANGED);

        if (img.empty()) {
            // Error message if image could not be loaded
            cout << "\n \t Image could not be loaded!";
        }
        else {
            // Success prompt for successful image loading
            cout << "\n \t Image found and loaded!";
            cout << "\n \t Initiating image processing...";
        }

        /*-----------------------------------------------------------------------------------------
            * Using vector data structure to store image data 
            * Vector "faces"     : stores the image data in a 2-dimensional form
            * detectMultiScale() : function is the classifier used to plot the features
            * Point pt1, pt2     : Template class for 2-D points specified by x, y coordinates
            * The program scans the face-2d-array and subsequently, if a face is found the
            * rectangle()        : draws a green rectangle around the feature - "face" in the image
            * Scalar()           : Template class for a 4-element vector derived from Vec, it passes
                                   the rectangle pixel values to the image
        -------------------------------------------------------------------------------------------*/

        vector<Rect> faces;
        faceDetection.detectMultiScale(img, faces);

        for (int i = 0; i < faces.size(); i++) {
            Point pt1(faces[i].x, faces[i].y);
            Point pt2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width));
            rectangle(img, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
        }

        /*-----------------------------------------------------------------------------------------
            * imwrite : writes this data as output to the predetermined-name output file
            * The directory for output is also predefined 
            * the function writes the output to the mentioned filename
            * and subsequently prints a successful completion prompt
        -------------------------------------------------------------------------------------------*/

        imwrite("C:\\Users\\user3\\Downloads\\output_facedetect.jpg", img);
        cout << "\n \t Face detection complete!";
        cout << "\n \t Written to output file successfully!";

        return 0;
    }
}
