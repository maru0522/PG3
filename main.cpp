#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "SceneManager.h"
#include <iostream>

int main(void) {

    SceneManager* sceneM = SceneManager::GetInstance();

    int num{};

    while (sceneM->currentScene_ < 4)
    {
        sceneM->Draw();

        std::cout << "enter next scene number" << std::endl;
        std::cin >> num;
        sceneM->ChangeScene(num);
    }

    system("pause");
    return 0;
}