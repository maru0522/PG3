#pragma once
#include <string>

class Pic
{
public:
    int32_t id_{};
    std::string name_{};
    std::string classroom_{};

    void DrawAll(void);
};

