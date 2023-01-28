#pragma once
class Enemy
{
public:
    // 静的関数
    static void Kill(Enemy instance);

private: 
    // 静的変数
    static bool isExist_;

public:
    // 関数
    Enemy(void) {};
    ~Enemy(void) {};

    void Update(void);
    void Draw(void);

private:
    // 変数
    bool isAlive_{ true };
};