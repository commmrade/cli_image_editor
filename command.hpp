#pragma once
#include <iostream>
//#include<opencv4/opencv2/opencv.hpp>

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
    static Action Parse();
};