#pragma once
#include "IShape.h"
class Circle :
    public IShape
{
private:
    // 定数
    static constexpr float PI = 3.141592f;

public:
    // 関数
    Circle(float radius);

    void Size(void) override;
    void Draw(void) override;

private:
    // 変数
    float radius_{};
    float area_{};
};

