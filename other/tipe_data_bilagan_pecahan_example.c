#include <stdio.h>

int main(){
    float a1;
    double a2;
    scanf("%f %lf", &a1, &a2);
    printf("Nilai a1 adalah: %.2f\n", a1);
    printf("Nilai a2 adalah: %.2f\n", a2);
    printf("Memori dari tipe data float: %lu\n", sizeof(float));
    printf("Memori dari tipe data double: %lu\n", sizeof(double));
    printf("Memori dari tipe data long double: %lu\n", sizeof(long double));

    return 0;
}
