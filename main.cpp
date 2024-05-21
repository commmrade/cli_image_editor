#include <exception>
#include <iostream>
#include<opencv2/core.hpp>
//#include<opencv4/opencv2/opencv.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include<ranges>

#include<format>
#include "image.hpp"
#include<opencv2/imgcodecs.hpp>
using namespace cv;


void error_send()
{
    std::cout << "Please use ./app path_to_img.jpg\n";
}

int main(int argc, char** argv){

    if(argc < 2) {
        error_send();
        return -1;
    }

    Image img(argv[1]);

    printf("Please enter an action (fliph, flipv, blur, scale, imgres, cut, rotate, exit): ");

    std::string action;
    std::cin >> action;

    if (action == "fliph")
    {
        printf("Flipping...\n");
        img.flip_horizontally();
    }
    else if (action == "flipv")
    {
        printf("Flipping...\n");
        img.flip_vertically();
    }
    else if (action == "scale")
    {
        uint scale;
        printf("Enter scale (2 means 2 times smaller): ");
        std::cin >> scale;
        printf("Processing...");
        img.scale_down(scale);
    }
    else if (action == "blur")
    {
        int scale;
        printf("Enter blur radius (0+): ");
        std::cin >> scale;
        
        if(scale < 0) {
            return -1;
        }
        printf("Processing...");
        
        
        img.blur(scale);
    }
    else if (action == "imgres")
    {
        std::cout << "Height: " << img.getImage().rows << "\nWidth: " << img.getImage().cols << std::endl;
    }
    else if (action == "cut")
    {
        printf("To cut an image from the source you need to enter from which Height, Width and to Height, Width you want to cut\n");
        int height_from;
        int height_to;
        int width_from;
        int width_to;

        printf("Enter start Height: ");
        std::cin >> height_from;
        printf("Enter end Height: ");
        std::cin >> height_to;

        printf("Enter start Width: ");
        std::cin >> width_from;
        printf("Enter end Width: ");
        std::cin >> width_to;

        img.cut(height_from, height_to, width_from, width_to);


    }
    else if (action == "rotate")
    {
        printf("Rotating...");
        img.rotate();
    }
    else
    {
        std::cout << "Exiting..." << std::endl;
    }
    
    //img = img.rotate();

    imwrite("output.jpg", img.getImage());
    
    

   

    return 0;
}
