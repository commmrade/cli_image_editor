#include "command.hpp"



Action Commands::Parse()
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