#pragma once
#include "IShape.h"
class RectAngle :
    public IShape
{
public:
    // �֐�
    RectAngle(float w,float h);

    void Size(void) override;
    void Draw(void) override;

private:
    // �ϐ�
    float w_{};
    float h_{};
    float area_{};
};

