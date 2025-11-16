#include <stdio.h>

int main(){
    char nama[31];
    char pekerjaan[21];

    printf("Nama : ");
    fgets(nama,30,stdin);
    printf("Pekerjaan : ");
    fgets(pekerjaan,20,stdin);
    printf("\nData yang telah dimasukkan adalah:\n");
    printf("Nama : %s", nama);
    printf("Pekerjaan : %s", pekerjaan);

    return 0;
}
