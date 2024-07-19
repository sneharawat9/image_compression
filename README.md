# image_compression
Image compression
Table of Contents

Chapter No.	Description	Page No.
Chapter 1	Introduction 	1
Chapter 2	Literature Survey	3
Chapter 3	Methodology	5
Chapter 4	Result and Discussion	8
Chapter 5	Conclusion and Future Work	10
	References	11










 
Chapter 1
Introduction 
Image compression is a vital process in the field of digital image processing, aimed at reducing the size of image files without compromising their visual quality significantly. With the ever-increasing use of digital images in various applications such as social media, web development, medical imaging, and satellite imagery, efficient storage and transmission of these images have become crucial. Image compression addresses this need by minimizing the file size, which in turn reduces the storage requirements and speeds up the transmission process over networks.
There are two primary types of image compression: lossy and lossless. Lossy compression reduces the file size by removing some of the image data, which can result in a slight loss of quality. JPEG (Joint Photographic Experts Group) is one of the most widely used lossy compression formats. It achieves high compression ratios by exploiting the limitations of human vision, discarding data that is less likely to be noticed by the human eye. On the other hand, lossless compression algorithms, such as PNG (Portable Network Graphics) and GIF (Graphics Interchange Format), compress the image data without any loss of quality, but typically achieve lower compression ratios compared to lossy methods.
In this project, we focus on implementing image compression using the C++ programming language, leveraging the capabilities of the OpenCV library. OpenCV (Open Source Computer Vision Library) is an open-source computer vision and machine learning software library. It contains a comprehensive set of functions and tools for image and video processing, making it an ideal choice for tasks such as image compression.
The primary objectives of this project are:
1.	To read an image file using OpenCV.
2.	To compress the image by adjusting the JPEG quality parameter.
3.	To save the compressed image to the disk.
4.	To display both the original and compressed images for comparison.
By achieving these objectives, we aim to demonstrate a practical approach to image compression, highlighting the balance between compression ratio and image quality. This project serves as an introductory exploration into the broader domain of image processing and compression techniques, providing a foundation for more advanced studies and applications.




















Chapter 2
Literature Survey
Image compression has been a significant area of research and development in the field of computer science and engineering for many years. Various techniques and algorithms have been developed to address the need for efficient storage and transmission of digital images. This section provides an overview of key concepts, algorithms, and tools relevant to image compression.
Historical Background
The early days of image compression were marked by simple techniques like run-length encoding (RLE), which was primarily used for compressing binary images. As the demand for more sophisticated image compression grew, particularly with the advent of multimedia and internet applications, more advanced algorithms were developed.
Compression Algorithms
1.	Lossy Compression:
o	JPEG (Joint Photographic Experts Group): Introduced in 1992, JPEG is the most widely used lossy compression standard. It employs a combination of discrete cosine transform (DCT), quantization, and entropy coding to achieve high compression ratios. The JPEG standard allows adjustable compression levels, enabling users to balance between image quality and file size.
o	HEVC (High Efficiency Video Coding): Also known as H.265, HEVC is primarily used for video compression but includes methods for still image compression. It offers superior compression efficiency compared to JPEG but at the cost of higher computational complexity.
2.	Lossless Compression:
o	PNG (Portable Network Graphics): Developed as a replacement for GIF, PNG uses lossless data compression via the DEFLATE algorithm. It is particularly suited for images requiring high fidelity, such as medical images and technical drawings.
o	GIF (Graphics Interchange Format): An older format that uses LZW (Lempel-Ziv-Welch) compression. It supports only 256 colors, making it less suitable for high-quality images but popular for simple graphics and animations.
OpenCV Library
OpenCV (Open Source Computer Vision Library) is an open-source library initially developed by Intel. It provides a wide range of tools and functions for image and video processing, computer vision, and machine learning. OpenCV's extensive functionality and ease of use have made it a popular choice for both academic research and industrial applications.
Key Functions in OpenCV for Image Compression
1.	cv::imread: This function reads an image from a file and stores it in a matrix (cv::Mat) format. It supports various image formats like JPEG, PNG, and BMP.
2.	cv::imwrite: This function writes an image to a file. It supports different image formats and allows specifying compression parameters, such as JPEG quality.
3.	cv::imshow: This function displays an image in a window, facilitating visualization and debugging during development.
Previous Studies and Applications
Several studies have explored the optimization and application of image compression techniques:
•	Medical Imaging: Efficient image compression is critical in telemedicine for transmitting medical images over limited bandwidth networks without losing diagnostic quality.
•	Satellite Imagery: Compression algorithms are essential for storing and transmitting large volumes of high-resolution satellite images.
•	Web Development: Optimized image compression techniques enhance website performance by reducing load times and improving user experience.





Chapter 3
Methodology 
The methodology for this project is designed to systematically achieve image compression using C++ and the OpenCV library. The process can be broken down into several key stages: reading the image, setting compression parameters, compressing and saving the image, and displaying the images for comparison. Each of these stages involves specific functions and techniques that leverage the capabilities of OpenCV to perform efficient image compression.
Reading the Image
The initial step in the process is to read an image file from the disk. This is achieved using the cv::imread function from the OpenCV library. The function takes the file path of the image as an argument and reads the image data into a matrix (cv::Mat) format. This matrix format is a core data structure in OpenCV that allows for efficient manipulation and processing of image data. The cv::imread function is capable of reading various image formats, including JPEG, PNG, and BMP, making it versatile for different use cases.
cpp
Copy code
cv::Mat image = cv::imread("C:/Users/Administrator/Desktop/imagecompression2/image.jpeg");
if (image.empty()) {
    std::cerr << "Error: Could not open or find the image!\n";
    return -1;
}
In the code above, the image is read from a specified path, and error handling is implemented to ensure that the image file is successfully loaded. If the image cannot be found or opened, an error message is displayed, and the program exits.
Setting Compression Parameters
Once the image is successfully loaded into memory, the next step is to set the compression parameters. JPEG compression is used in this project due to its widespread use and ability to balance compression efficiency with image quality. The compression parameters are specified using a vector, with the key parameter being cv::IMWRITE_JPEG_QUALITY. This parameter controls the quality of the compressed image on a scale from 0 to 100, where lower values correspond to higher compression and lower image quality.
cpp
Copy code
std::vector<int> compression_params;
compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
compression_params.push_back(20); // Adjust the quality (0-100)
In this example, a quality value of 20 is chosen, which provides a significant reduction in file size while maintaining an acceptable level of image quality. The vector allows for flexible and dynamic setting of multiple compression parameters if needed.
Compressing and Saving the Image
With the compression parameters set, the next step is to compress and save the image using the cv::imwrite function. This function takes three arguments: the file path for the compressed image, the image matrix, and the compression parameters. The function writes the image to the specified file path using the provided compression settings.
cpp
Copy code
bool result = cv::imwrite("compressed.jpg", image, compression_params);
if (result) {
    std::cout << "Image compression successful!\n";
} else {
    std::cerr << "Error: Could not save the compressed image!\n";
    return -1;
}
In the code above, the cv::imwrite function attempts to save the compressed image to a file named "compressed.jpg". If the function succeeds, a success message is displayed. If it fails, an error message is shown, and the program exits. This ensures that the process handles errors gracefully and provides feedback to the user.
Displaying the Images
After compressing and saving the image, the final step is to display both the original and compressed images for comparison. This is accomplished using the cv::imshow function, which creates windows to display the images.
cpp
Copy code
cv::imshow("Original Image", image);
cv::Mat compressedImage = cv::imread("compressed.jpg");
cv::imshow("Compressed Image", compressedImage);
The original image is displayed first, followed by the compressed image. This visual comparison allows for an immediate assessment of the compression quality and the trade-offs between file size and image fidelity.
Waiting for User Input
The program concludes by waiting for a key press from the user. This is done using the cv::waitKey function, which keeps the display windows open until the user decides to close them. This function is essential for interactive applications, allowing users to view the images at their convenience.
cpp
Copy code
cv::waitKey(0);
In summary, the methodology of this project involves a series of well-defined steps that leverage the powerful image processing capabilities of OpenCV. By systematically reading, compressing, saving, and displaying the images, the project demonstrates a practical and effective approach to image compression using C++. The provided code serves as a clear example of how to utilize OpenCV functions to achieve efficient image compression while maintaining a balance between file size and image quality.


Chapter 4
Result and Discussion
The implementation of the image compression project using C++ and OpenCV was successful in achieving its primary objectives. The following results and observations were made during the execution of the project.
Image Reading and Compression
The original image was successfully read from the specified file path using the cv::imread function. The image data was loaded into a cv::Mat object, allowing for efficient manipulation and processing. The implementation included error handling to ensure that any issues with reading the image were appropriately handled, and an error message was displayed if the image could not be opened.
The compression parameters were set using a std::vector, with the key parameter being cv::IMWRITE_JPEG_QUALITY set to 20. This setting provided a balance between compression ratio and image quality. The cv::imwrite function was then used to compress and save the image as "compressed.jpg". The success of the image compression was confirmed by the display of a success message, and appropriate error handling was implemented in case the image could not be saved.
Image Display and Comparison
Both the original and compressed images were displayed using the cv::imshow function. This allowed for a visual comparison between the original and compressed images. The compressed image showed a noticeable reduction in file size while maintaining an acceptable level of visual quality. The display windows remained open until a key press was detected, allowing the user to view the images at their convenience.
Performance and Quality
The chosen compression quality setting of 20 resulted in a significant reduction in file size. This demonstrates the effectiveness of JPEG compression in reducing storage requirements and transmission times. While there was some loss in image quality due to the lossy nature of JPEG compression, the resulting image remained visually acceptable for most purposes.
Discussion
The results highlight the effectiveness of using OpenCV for image compression tasks. OpenCV's robust functions and ease of use significantly simplify the process of reading, compressing, and displaying images. The ability to adjust compression parameters provides flexibility in balancing file size and image quality, catering to different application needs.
The project demonstrates a practical approach to image compression, showcasing the capabilities of C++ and OpenCV in handling such tasks. The use of error handling ensures the robustness of the implementation, providing appropriate feedback to the user in case of issues.
















Chapter 5
Conclusion and Future Work 
In conclusion, the project successfully implemented image compression using C++ and OpenCV. The key objectives of reading an image, compressing it, saving the compressed image, and displaying both the original and compressed images were achieved. The project demonstrated the effectiveness of JPEG compression in reducing file size while maintaining acceptable image quality.
The use of OpenCV significantly simplified the process, providing powerful functions for image manipulation and processing. The implementation included error handling to ensure robustness and provide feedback to the user.
Future Work
While the current implementation provides a basic yet effective solution for image compression, there are several areas for future improvement and exploration:
1.	Support for Multiple Formats: Extend the functionality to support other image formats like PNG and GIF, including both lossy and lossless compression techniques.
2.	Graphical User Interface: Develop a user-friendly graphical interface to allow users to easily select images, adjust compression parameters, and view results.
3.	Batch Processing: Implement features to batch process multiple images, which is useful for large-scale applications such as photo archives or web development.
4.	Advanced Compression Algorithms: Explore more advanced compression algorithms that can achieve better compression ratios without significant loss in image quality, such as HEVC or machine learning-based methods.
5.	Performance Optimization: Optimize the performance of the compression process, particularly for high-resolution images, to ensure quick and efficient processing.





References
[1] Pratt, William K. "Digital Image Processing: PIKS Inside." John Wiley & Sons, 2007.
[2] Gonzalez, Rafael C., and Woods, Richard E. "Digital Image Processing." Pearson Education, 2017.
[3] Wallace, Gregory K. "The JPEG Still Picture Compression Standard." IEEE Transactions on Consumer Electronics, 1991.
[4] Sayood, Khalid. "Introduction to Data Compression." Morgan Kaufmann, 2017.
[5] www.wikipedia.com




