#include "Pic.h"
#include <iostream>

void Pic::DrawAll(void)
{
    std::cout << "ID : " << id_ << ", 名前 : " << name_ << ", クラス : " << classroom_ << std::endl;
}
