#include <stdio.h>

template<class T>
T Min(T a, T b) {
    if (a <= b) {
        return a;
    }

    return b;
}

template<>
char Min<char>(char a, char b) {
    printf("”šˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñB");
    return 0;
}

int main(void) {
    printf("%d\n", Min<int>(100, 200));
    printf("%f\n", Min<float>(10.2f, 20.8f));
    printf("%lf\n", Min<double>(10.22f, 20.88f));
    printf("%c\n", Min<char>('a', 'b'));

    return 0;
}