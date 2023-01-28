#pragma once
#include "IShape.h"
class RectAngle :
    public IShape
{
public:
    // ŠÖ”
    RectAngle(float w,float h);

    void Size(void) override;
    void Draw(void) override;

private:
    // •Ï”
    float w_{};
    float h_{};
    float area_{};
};

