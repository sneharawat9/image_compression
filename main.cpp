#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Read the image
    cv::Mat image = cv::imread("C:/Users/Administrator/Desktop/imagecompression2/image.jpeg");

    if (image.empty()) {
        
        std::cerr << "Error: Could not open or find the image!\n";
        return -1;
    }

    // Set the compression parameters
    std::vector<int> compression_params;
    compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
    compression_params.push_back(20); // Adjust the quality (0-100)

    // Write the compressed image
    bool result = cv::imwrite("compressed.jpg", image, compression_params);

    if (result) {
        std::cout << "Image compression successful!\n";
    } else {
        std::cerr << "Error: Could not save the compressed image!\n";
        return -1;
    }

     // Display the original and compressed images
    cv::imshow("Original Image", image);
    cv::Mat compressedImage = cv::imread("compressed.jpg");
    cv::imshow("Compressed Image", compressedImage);

    // Wait for a key press indefinitely
    cv::waitKey(0);

    return 0;
}