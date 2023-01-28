#pragma once
#include "IShape.h"
class Circle :
    public IShape
{
private:
    // �萔
    static constexpr float PI = 3.141592f;

public:
    // �֐�
    Circle(float radius);

    void Size(void) override;
    void Draw(void) override;

private:
    // �ϐ�
    float radius_{};
    float area_{};
};

