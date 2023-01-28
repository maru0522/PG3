#include "Rectangle.h"
#include <iostream>

RectAngle::RectAngle(float w, float h) :
    w_(w),
    h_(h)
{
}

void RectAngle::Size(void)
{
    area_ = w_ * h_;
}

void RectAngle::Draw(void)
{
    std::cout << "–ÊÏ‚Í" << area_ << "‚Å‚·" << std::endl;
}
