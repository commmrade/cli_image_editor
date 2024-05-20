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
    std::cout << "Please use ./app path_to_img <fliph, flipv, scale, blur> <multiplier (if scale, blur)>\n";
}

int main(int argc, char** argv){

    if(argc < 2) {
        error_send();
        return -1;
    }
     
    //std::cout << argv[1] << std::endl;
    std::string action = argv[2];
    //Mat img = imread(argv[1]);
    Image img(argv[1]);
    std::cout << img.getImage().rows << std::endl;
    if(action == "fliph") {
        std::cout << "flipping...\n";
        //img = flip_img_h(img);
        img.flip_horizontally();
    }
    else if (action == "flipv") {
        std::cout << "flipping...\n";
        //img = flip_img_v(img);
        img.flip_vertically();
    }
    else if(action == "scale") {
        std::cout << std::format("scaling down by {}", atoi(argv[3])) << std::endl;
        
        //img = scaleD_img(img, atoi(argv[3]));
        img.scale_down(atoi(argv[3]));
    }
    else if (action == "blur"){
        std::cout << std::format("blurring by {}", atoi(argv[3])) << std::endl;
        //img = blur_img(img, atoi(argv[3]));
        img.blur(atoi(argv[3]));
    }
    else {
        error_send();
        return -1;
    }
    



    imwrite("output.jpg", img.getImage());
    
    

   

    return 0;
}
