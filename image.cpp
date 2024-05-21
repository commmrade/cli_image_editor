#include "image.hpp"
#include <cstdlib>
#include <opencv2/core/hal/interface.h>
#include <opencv2/core/matx.hpp>

Image::Image(const char *path) {
    img = imread(path);
    if(img.data == NULL)
    {
        exit(EXIT_FAILURE); // If file doesnt exist or sommething else hapenned
    }
}

Image::Image(uint width, uint height)
{
    img = Mat::zeros(Size(height, width), CV_8UC3); //Default init image
}

Mat Image::flip_img_h(Mat img_f)
{
    Mat img = img_f.clone();

    int width = img.cols;
    int height = img.rows;

    parallel_for_(Range(0, width / 2), [&](const Range &range)
    {
        for(auto i = range.start; i < range.end; ++i)
        {
            // for(auto j = 0; j < height; ++j)
            for(auto j : std::views::iota(0, height))
            {
                std::swap(img.at<Vec3b>(j, i), img.at<Vec3b>(j, width - i)); // Swapping left side of the image with right
            }
        }
    });
    
    return img;
}
Mat Image::flip_img_v(Mat img_f)
{
    Mat img = img_f.clone();

    int width = img.cols;
    int height = img.rows;

    parallel_for_(Range(0, height / 2), [&](const Range &range)
    {
        for(auto i = range.start; i < range.end; ++i)
        {
            // for(auto j = 0; j < height; ++j)
            for(auto j : std::views::iota(0, width))
            {
                std::swap(img.at<Vec3b>(i, j), img.at<Vec3b>(height - i - 1, j)); //Swapping top half pixels with bottom half (-1 in order to NOT go out of bounds)
            }
        }
    });
    
    return img;
}

Mat Image::blur_img(Mat imgf, int blur_str)
{
    Mat blurred_img = imgf.clone(); // so we wo nt change original image

    int width = blurred_img.cols;
    int height = blurred_img.rows;

    int blur_strength = blur_str;


    parallel_for_(Range(0, width - blur_strength), [&](const Range &range) //Makes it multithreaded
    {
        for(int i = range.start; i < range.end; ++i) //Iter through all pixels
        {
            //for(int j = 0; j < height - blur_strength; ++j)
            for(auto j : std::views::iota(0, height - blur_strength))
            {
                auto sum = Vec3i(0, 0, 0);


                //for(int k = 0; k < blur_strength; ++k)
                for(auto k : std::views::iota(0, blur_strength))
                {
                    //for(int l = 0; l < blur_strength; ++l)
                    for(auto l : std::views::iota(0, blur_strength))
                    {
                        sum += imgf.at<Vec3b>(j + k, i + l); //Averaging colors in range 5x5 for example
                    }
                }


                blurred_img.at<Vec3b>(j, i) = sum / (blur_strength * blur_strength); //Dividing by pixels amount to get average
            }
        }
    });

    // TODO:
    //     FIX BORDERS
    //     TODO:
    //     FIX BORDERS
    //     TODO:
    //     FIX BORDERS
    //     TODO:
    //     FIX BORDERS
    //     TODO:
    //     FIX BORDERS
    //     TODO:
    //     FIX BORDERS
    //     TODO:
    //     FIX BORDERS
    //     TODO:
    //     FIX BORDERS
    //     TODO:
    //     FIX BORDERS

    return blurred_img;
}
Mat Image::scaleD_img(Mat imgf, int sFactor)
{
    
    int width = imgf.cols;
    int height = imgf.rows;

    int new_wd = width / sFactor; //Scaled down resolution
    int new_ht = height / sFactor; 

    Mat img(new_ht, new_wd, imgf.type());

    for(auto i = 0; i < new_wd; ++i)
    {
        for(auto j = 0; j < new_ht; ++j)
        {
            img.at<Vec3b>(j, i) = imgf.at<Vec3b>(j * sFactor, i * sFactor); // Multiplying width and height to correspond to the original image
        }
    }

    return img;
}
Mat Image::rotate_img()
{
    Mat res(Size(img.rows, img.cols), CV_8UC3); //Using width as height and height as width


    for(auto i : std::views::iota(0, res.rows))
    {
        for(auto j : std::views::iota(0, res.cols))
        {
            res.at<Vec3b>(i, j) = img.at<Vec3b>(j, i); 
        }
    }

    res = flip_img_v(res); //Without this the image is rotated clockwise


    return res;
}
Mat Image::cut_img(int height_from, int height_to, int width_from, int width_to)
{
    Mat res(Size(width_to - width_from, height_to - height_from), CV_8UC3);

    for(auto i : std::views::iota(0, height_to - height_from))
    {
        for(auto j : std::views::iota(0, width_to - width_from))
        {
            res.at<Vec3b>(i, j) = img.at<Vec3b>(i + height_from, j + width_from);
        }
    }
    return res;
}







void Image::flip_horizontally()
{
    img = flip_img_h(img);
}
void Image::flip_vertically()
{
    img = flip_img_v(img);
}
void Image::blur(int strength)
{
    img = blur_img(img, strength);
}
void Image::scale_down(int scale)
{
    img = scaleD_img(img, scale);
}
void Image::rotate()
{
    img = rotate_img();
}
void Image::cut(int height_from, int height_to, int width_from, int width_to)
{
    img = cut_img(height_from, height_to, width_from, width_to);
}

