#include <stdio.h>
#include "Enemy.h"
#include <array>
#include <iostream>
#include <Windows.h>

int main(void) {
    Enemy enemy;

    for (size_t i = 0; i < 3; i++) {
        enemy.Update();
        Sleep(2000);
    }

    system("pause");

    return 0;
}