#pragma once
class Enemy
{
public:
    // �ÓI�֐�
    static void Kill(Enemy instance);

private: 
    // �ÓI�ϐ�
    static bool isExist_;

public:
    // �֐�
    Enemy(void) {};
    ~Enemy(void) {};

    void Update(void);
    void Draw(void);

private:
    // �ϐ�
    bool isAlive_{ true };
};