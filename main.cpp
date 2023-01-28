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

    std::cout << "‰½”Ô–Ú‚Ì“G‚ð“|‚·‚©0~2‚ÅŽw’è‚µ‚Ä‚­‚¾‚³‚¢" << std::endl;
    std::cin >> idx;

    Enemy::Kill(enemies.at(idx));

    for (size_t i = 0; i < enemies.size(); i++) {
        enemies.at(i).Update();
        enemies.at(i).Draw();
    }

    return 0;
}