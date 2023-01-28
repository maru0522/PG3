#include "Enemy.h"
#include <iostream>

bool Enemy::isExist_{ false };

void Enemy::Kill(Enemy instance)
{
    instance.isAlive_ = false;
}

void Enemy::Update(void)
{
    if (!isAlive_) isExist_ = false;
    if (!isExist_) isAlive_ = false;
}

void Enemy::Draw(void)
{
    if (isAlive_) std::cout << "alive!" << std::endl;
    else std::cout << "dead" << std::endl;
}
