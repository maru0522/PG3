#include "SceneManager.h"
#include <iostream>

SceneManager* SceneManager::GetInstance(void)
{
    static SceneManager instance;
    return &instance;
}

void SceneManager::Draw(void)
{
    if (currentScene_ == 0) {
        std::cout << "SCENE: Title" << std::endl;
    }
    else if (currentScene_ == 1) {
        std::cout << "SCENE: NewGame" << std::endl;
    }
    else if (currentScene_ == 2) {
        std::cout << "SCENE: GamePlay" << std::endl;
    }
    else if (currentScene_ == 3) {
        std::cout << "SCENE: GameClear" << std::endl;
    }
}
