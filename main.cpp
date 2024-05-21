#include <cstdlib>
#include <iostream>
#include<opencv2/core.hpp>
#include<ranges>
#include"command.hpp"
#include<format>
#include "image.hpp"
#include<opencv2/imgcodecs.hpp>
using namespace cv;


void error_send()
{
    std::cout << "Please use ./app path_to_img.jpg\n";
}

void foo(Mat img)
{
    for(auto i : std::views::iota(0, img.rows))
    {
        for(auto j : std::views::iota(0, img.cols))
        {
            img.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
        }
    }
}


int main(int argc, char** argv){



    if(argc < 2) {
        error_send();
        return -1;
    }

    Image img(argv[1]);

    Action action = Commands::Parse();

    //printf("Please enter an action (fliph, flipv, blur, scale, imgres, cut, rotate, exit): ");

    
    switch (action)
    {
        case FlipHorizontal:
            printf("Flipping...\n");
            img.flip_horizontally(); 
            break;

        case FlipVertical:
            printf("Flipping...\n");
            img.flip_vertically();
            break;

        case Scale:
            uint scale;
            printf("Enter scale (2 means 2 times smaller): ");
            std::cin >> scale;
            printf("Processing...");
            img.scale_down(scale);
            break;
        
        case Blur:
            int blur_str;
            printf("Enter blur radius (0+): ");
            std::cin >> blur_str;
            
            if(blur_str < 0) {
                return -1;
            }
            printf("Processing...");
            img.blur(blur_str);
            break;
        
        case ImageResolution:
            std::cout << "Height: " << img.getImage().rows << "\nWidth: " << img.getImage().cols << std::endl;
            exit(EXIT_SUCCESS);
            break;
        
        case Cut:
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
            break;
        
        case Rotate:
            printf("Rotating...");
            img.rotate();
            break;
        
        case Exit:
            std::cout << "Exiting..." << std::endl;
            return 0;
            break;

    }

    
    //img = img.rotate();

    imwrite("output.jpg", img.getImage());

 
    
    

   

    return 0;
}
