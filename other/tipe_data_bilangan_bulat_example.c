#include <stdio.h>

int main(){
    int x;
    long int y;
    unsigned int z;
    scanf("%i %li %u", &x, &y, &z);
    printf("Nilai x yang telah diberikan adalah %i\n", x);
    printf("Nilai y yang telah diberikan adalah %li\n", y);
    printf("Nilai z yang telah diberikan adalah %u\n", z);
    printf("Memori dari tipe data int: %lu\n", sizeof(int));
    printf("Memori dari tipe data unsigned int: %lu\n", sizeof(unsigned int));
    printf("Memori dari tipe data signed int: %lu\n", sizeof(signed int));
    printf("Memori dari tipe data short int: %lu\n", sizeof(short int));
    printf("Memori dari tipe data unsigned short int: %lu\n", sizeof(unsigned short int));
    printf("Memori dari tipe data signed short int: %lu\n", sizeof(signed short int));
    printf("Memori dari tipe data long int: %lu\n", sizeof(long int));
    printf("Memori dari tipe data signed long int: %lu\n", sizeof(signed long int));
    printf("Memori dari tipe data unsigned long int: %lu\n", sizeof(unsigned long int));

    return 0;
}
