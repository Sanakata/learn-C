#include <stdio.h>

int main(){
    char A1, A2;
    scanf("%c", &A1);
    A2 = A1;
    printf("A1: %c\n", A1);
    printf("A2 (ASCII): %i\n", A2);

    printf("Memori dari tipe data char: %lu\n", sizeof(char));
    printf("Memori dari tipe data unsigned char: %lu\n", sizeof(unsigned char));
    printf("Memori dari tipe data signed char: %lu\n", sizeof(signed char));

    return 0;
}
