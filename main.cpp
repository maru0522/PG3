#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <iostream>

using PFunc = void (*) (int);

// �R�[���o�b�N�֐�
void Callback1(int num) {
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

void SetTimeout(PFunc p, int second,int num) {
    std::cout << second << "�b�҂��Ă��������B" << std::endl;
    std::cout << "�T�C�R����U���Ă��܂��B" << std::endl;
    // �ҋ@
    Sleep(second * 1000);
    p(num);
}


int main(void) {

    int num{ 0 };

    std::cout << "����/��ǂ���ɂȂ邩�\�z���l����͂��Ă��������B" << std::endl;
    std::cout << "�����Ȃ�[0]���A��Ȃ�[1]����͂��Ă��������B" << std::endl;

    std::cin >> num;

    // 0��1��K�����͂�����
    while (num != 0 && num != 1) {
        std::cout << "���͂��ꂽ�l���s�K�؂ł��B�����Ȃ�[0]���A��Ȃ�[1]����͂��Ă��������B" << std::endl;
        std::cin >> num;
    }

    PFunc p;
    p = Callback1;

    // �֐��|�C���^, �ҋ@����[s], �\�z���ꂽ�l
    SetTimeout(p, 3, num);

    return 0;
}