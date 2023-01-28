#include "Enemy.h"
#include <iostream>

void (Enemy::* Enemy::spFuncTable[])() = {
    &Enemy::MeleeAttack,
    &Enemy::SHOOTAttack,
    &Enemy::Leave
};

void Enemy::Update(void)
{
    (this->*spFuncTable[static_cast<size_t>(state_)])();
}

void Enemy::MeleeAttack(void)
{
    std::cout << "i do melee attack" << std::endl;
    state_ = State::SHOOT;
}

void Enemy::SHOOTAttack(void)
{
    std::cout << "i do shoot attack" << std::endl;
    state_ = State::LEAVE;
}

void Enemy::Leave(void)
{
    std::cout << "i leave here" << std::endl;
}
