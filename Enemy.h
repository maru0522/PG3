#pragma once

class Enemy
{
public:
    // 定義
    enum class State
    {
        MELEE,
        SHOOT,
        LEAVE,
    };

    // 関数
    Enemy(void) {};
    ~Enemy(void) {};

    void Update(void);

private:
    void MeleeAttack(void);
    void SHOOTAttack(void);
    void Leave(void);

private:
    // 変数
    static void (Enemy::*spFuncTable[])();

    State state_{};
};