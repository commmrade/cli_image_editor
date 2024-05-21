#pragma once
#include <iostream>
#include<opencv2/core.hpp>
//#include<opencv4/opencv2/opencv.hpp>
#include <opencv2/core/cvstd.hpp>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include<ranges>
#include<format>
#include<opencv2/imgcodecs.hpp>
#include <sys/types.h>



enum Action
{
    FlipVertical,
    FlipHorizontal,
    Blur,
    Scale,
    ImageResolution,
    Cut,
    Rotate,
    Exit
};

class Commands
{
private:

public:
    static Action Parse()
    {
        printf("Please enter an action (fliph, flipv, blur, scale, imgres, cut, rotate, exit): ");

        std::string action;
        std::cin >> action;

        if (action == "fliph")
        {
            return FlipHorizontal;
        }
        else if (action == "flipv")
        {
            return FlipVertical;
        }
        else if (action == "scale")
        {
            return Scale;
        }
        else if (action == "blur")
        {
            return Blur;
        }
        else if (action == "imgres")
        {
            return ImageResolution;
        }
        else if (action == "cut")
        {
            return Cut;

        }
        else if (action == "rotate")
        {
            return Rotate;
        }
        else
        {
            return Exit;
        }
    
    }
};