#pragma once
#include "IShape.h"
class Circle :
    public IShape
{
private:
    // ’è”
    static constexpr float PI = 3.141592f;

public:
    // ŠÖ”
    Circle(float radius);

    void Size(void) override;
    void Draw(void) override;

private:
    // •Ï”
    float radius_{};
    float area_{};
};

