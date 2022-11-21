#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <functional>

using PFunc = void (*) (int);

// �R�[���o�b�N�֐�
void Dice(int num) {
    srand(time(nullptr));

    int randNum{ rand()%6 + 1 };
    std::cout << "�T�C�R���̒l��" << randNum << "�ł����B" << std::endl;

    if (num % 2 == randNum % 2) {
        std::cout << "���Ȃ��̏����B" << std::endl;
    }
    else {
        std::cout << "���Ȃ��̕����B" << std::endl;
    }
}

int main(void) {
    int num{ 0 };

    std::cout << "����/��ǂ���ɂȂ邩�\�z���l����͂��Ă��������B" << std::endl;
    std::cout << "�����Ȃ�[0]���A��Ȃ�[1]����͂��Ă��������B" << std::endl;

    std::cin >> num;

    std::function<void(PFunc, int)> setTimeout = [=](PFunc fx, int second){
        std::cout << second << "�b�҂��Ă��������B" << std::endl;
        // �ҋ@
        Sleep(second * 1000);
        fx(num);
    };

    // 0��1��K�����͂�����
    while (num != 0 && num != 1) {
        std::cout << "���͂��ꂽ�l���s�K�؂ł��B�����Ȃ�[0]���A��Ȃ�[1]����͂��Ă��������B" << std::endl;
        std::cin >> num;
    }

    PFunc fx;
    fx = Dice;

    // �ҋ@����[s], �\�z���ꂽ�l
    setTimeout(fx, 3);

    system("pause");
    return 0;
}