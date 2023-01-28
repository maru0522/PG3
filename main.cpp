#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <functional>
#include "Circle.h"
#include "Rectangle.h"

int main(void) {
    Circle circle{ 5 };
    circle.Size();
    circle.Draw();

    RectAngle rect{ 5,10 };
    rect.Size();
    rect.Draw();

    system("pause");
    return 0;
}