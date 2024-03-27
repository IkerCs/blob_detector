#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

#include "blob_detection.h"

int main() {
    std::cout << "USING OPENCV VERSION: " << CV_VERSION << std::endl;

    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Error opening camera" << std::endl;
        return -1;
    }

    BlobDetection ballDetection;
    ballDetection.set_color_range(cv::Scalar(40, 46, 172), cv::Scalar(111, 131, 250));
    ballDetection.set_area(500, 100000);


    while (true) {
        cv::Mat frame;
        cap >> frame;

        std::vector<BlobDetection::Blob> blobs = ballDetection.detect(frame);
        BlobDetection::plot_blobs(frame, blobs);

        cv::imshow("Frame", frame);

        if (cv::waitKey(10) == 27) {
            break;
        }
    }

    return 0;
}
