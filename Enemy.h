#pragma once

class Enemy
{
public:
    // ’è‹`
    enum class State
    {
        MELEE,
        SHOOT,
        LEAVE,
    };

    // ŠÖ”
    Enemy(void) {};
    ~Enemy(void) {};

    void Update(void);

private:
    void MeleeAttack(void);
    void SHOOTAttack(void);
    void Leave(void);

private:
    // •Ï”
    static void (Enemy::*spFuncTable[])();

    State state_{};
};