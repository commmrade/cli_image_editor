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


using namespace cv;


class Image
{
private:
    Mat img;

    Mat flip_img_h(Mat img_f);
    Mat flip_img_v(Mat img_f);
    Mat blur_img(Mat imgf, int blur_str);
    Mat scaleD_img(Mat imgf, int sFactor);

public:

    Image(const char *path);
    Image(uint width, uint height);

    Mat& getImage() {return img;};

    void flip_horizontally();
    void flip_vertically();
    void blur(int strength);
    void scale_down(int scale);
    Image cut(int height_from, int height_to, int width_from, int width_to);



};