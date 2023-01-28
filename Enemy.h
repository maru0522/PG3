#pragma once

class Enemy
{
public:
    // ��`
    enum class State
    {
        MELEE,
        SHOOT,
        LEAVE,
    };

    // �֐�
    Enemy(void) {};
    ~Enemy(void) {};

    void Update(void);

private:
    void MeleeAttack(void);
    void SHOOTAttack(void);
    void Leave(void);

private:
    // �ϐ�
    static void (Enemy::*spFuncTable[])();

    State state_{};
};