#include <stdio.h>

// ��ʑ̌n
int General(int hourlyWage, int hours) {
    return hourlyWage * hours;
}

// �ċA�̌n
int Recursive(int defWage, int hours) {
    if (hours <= 0) {
        return 0;
    }

    return defWage + Recursive(defWage * 2 - 50, hours - 1);
}

int main(void) {
    const int hourlyWage = 1072;    // ��ʑ̌n�̎���
    const int beginWage = 100;      // �ċA�̌n�̏�������

    int workTime = 8; // �J������


    // �J�����ԕ��̋�����r
    printf("��ʓI�Ȓ����̌n : %d�~\n", General(hourlyWage, workTime));
    printf("�ċA�I�Ȓ����̌n : %d�~\n", Recursive(beginWage, workTime));

    // ���_
    if (General(hourlyWage, workTime) >= Recursive(beginWage, workTime)) {
        printf("����Ĉ�ʓI�Ȓ����̌n�̕��������������B\n");
    }
    else {
        printf("����čċA�I�Ȓ����̌n�̕��������������B\n");
    }

    return 0;
}