#include <stdio.h>

// ˆê”Ê‘ÌŒn
int General(int hourlyWage, int hours) {
    return hourlyWage * hours;
}

// Ä‹A‘ÌŒn
int Recursive(int defWage, int hours) {
    if (hours <= 0) {
        return 0;
    }

    return defWage + Recursive(defWage * 2 - 50, hours - 1);
}

int main(void) {
    const int hourlyWage = 1072;    // ˆê”Ê‘ÌŒn‚Ì‹‹
    const int beginWage = 100;      // Ä‹A‘ÌŒn‚Ì‰Šú’À‹à

    int workTime = 8; // ˜J“­ŠÔ


    // ˜J“­ŠÔ•ª‚Ì‹‹—¿”äŠr
    printf("ˆê”Ê“I‚È’À‹à‘ÌŒn : %d‰~\n", General(hourlyWage, workTime));
    printf("Ä‹A“I‚È’À‹à‘ÌŒn : %d‰~\n", Recursive(beginWage, workTime));

    // Œ‹˜_
    if (General(hourlyWage, workTime) >= Recursive(beginWage, workTime)) {
        printf("‚æ‚Á‚Äˆê”Ê“I‚È’À‹à‘ÌŒn‚Ì•û‚ª’À‹à‚ª‘½‚¢B\n");
    }
    else {
        printf("‚æ‚Á‚ÄÄ‹A“I‚È’À‹à‘ÌŒn‚Ì•û‚ª’À‹à‚ª‘½‚¢B\n");
    }

    return 0;
}