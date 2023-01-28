#include <stdio.h>
#include "Enemy.h"
#include <array>
#include <iostream>

int main(void) {
    std::array<Enemy, 3> enemies{};

    uint32_t idx{};

    for (size_t i = 0; i < enemies.size(); i++) {
        enemies.at(i).Draw();
    }

    std::cout << "何番目の敵を倒すか0~2で指定してください" << std::endl;
    std::cin >> idx;

    Enemy::Kill(enemies.at(idx));

    for (size_t i = 0; i < enemies.size(); i++) {
        enemies.at(i).Update();
        enemies.at(i).Draw();
    }

    system("pause");

    return 0;
}