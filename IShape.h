#pragma once
class IShape
{
public:
    // �֐�
    virtual ~IShape(void) = default;

    virtual void Size(void) = 0;
    virtual void Draw(void) = 0;
};

