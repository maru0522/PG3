#pragma once
class Enemy
{
public:
    // Ã“IŠÖ”
    static void Kill(Enemy instance);

private: 
    // Ã“I•Ï”
    static bool isExist_;

public:
    // ŠÖ”
    Enemy(void) {};
    ~Enemy(void) {};

    void Update(void);
    void Draw(void);

private:
    // •Ï”
    bool isAlive_{ true };
};