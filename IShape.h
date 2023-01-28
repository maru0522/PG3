#pragma once
class IShape
{
public:
    // ä÷êî
    virtual ~IShape(void) = default;

    virtual void Size(void) = 0;
    virtual void Draw(void) = 0;
};

