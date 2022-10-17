#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <functional>

using PFunc = void (*) (int);

// コールバック関数
void Callback1(int num) {
    srand(time(nullptr));

    int randNum{ rand()%6 + 1 };
    std::cout << "サイコロの値は" << randNum << "でした。" << std::endl;

    if (num % 2 == randNum % 2) {
        std::cout << "あなたの勝ち。" << std::endl;
    }
    else {
        std::cout << "あなたの負け。" << std::endl;
    }
}

int main(void) {
    int num{ 0 };

    std::cout << "偶数/奇数どちらになるか予想し値を入力してください。" << std::endl;
    std::cout << "偶数なら[0]を、奇数なら[1]を入力してください。" << std::endl;

    std::cin >> num;

    std::function<void(PFunc,int)> setTimeout = [=](PFunc p, int second){
        std::cout << second << "秒待ってください。" << std::endl;
        std::cout << "サイコロを振っています。" << std::endl;
        // 待機
        Sleep(second * 1000);
        p(num);
    };

    // 0か1を必ず入力させる
    while (num != 0 && num != 1) {
        std::cout << "入力された値が不適切です。偶数なら[0]を、奇数なら[1]を入力してください。" << std::endl;
        std::cin >> num;
    }

    PFunc p;
    p = Callback1;

    // 関数ポインタ, 待機時間[s], 予想された値
    setTimeout(p, 3);

    return 0;
}