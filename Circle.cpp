#include "Circle.h"
#include <iostream>

Circle::Circle(float radius) :
    radius_(radius)
{
}

void Circle::Size(void)
{
    area_ = radius_ * radius_ * PI;
}

void Circle::Draw(void)
{
    std::cout << "�ʐς�" << area_ << "�ł�" << std::endl;
}
