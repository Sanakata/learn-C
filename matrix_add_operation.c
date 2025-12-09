#include <stdio.h>
#include <stdlib.h>


void scan_matrix_size(int r[], int c[]){
    int r_temp, c_temp;
    for(int i = 0; i < 2; i++){
        printf("Matrix number %d\n", i + 1);
        printf("Input amount of row: ");
        scanf("%d", &r_temp);
        r[i] = r_temp;
        printf("Input amount of collumn: ");
        scanf("%d", &c_temp);
        c[i] = c_temp;
    }
    printf("\n");
}

void handle_invalid_size(int r[2], int c[2]){
    if(r[0] != r[1] || c[0] != c[1]){
        printf("Error occured\nThe matrix size is not equal\nPlease input the same size next time :D\n");
        exit(1);
    }
}

void scan_matrix_elements(int R, int C, int matrix[R][C], int matrix_num){
    printf("Scan elements for matrix number %d\n", matrix_num);
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            printf("Input matrix element at index [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n");
}

void print_matrix_elements(int R, int C, int matrix[R][C], int matrix_num){
    printf("Print elements for matrix number %d\n", matrix_num);
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_add_matrix_elements(int R, int C, int matrix_a[R][C], int matrix_b[R][C]){
    printf("The addition results of two matrixes is\n");
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            printf("%d ", matrix_a[i][j] + matrix_b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int add_element(int a, int b){
    return a + b;
}

void save_add_matrix_elements(int R, int C, int matrix_a[R][C], int matrix_b[R][C], int matrix_c[R][C]){
    printf("Saves the addition of Matrix 1 and 2 into Matrix 3\n");
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            matrix_c[i][j] = add_element(matrix_a[i][j], matrix_b[i][j]);
        }
    }
    printf("\n");
}


int main(){
    int c[2], r[2];
    scan_matrix_size(r, c);
    handle_invalid_size(r, c);
    int R = r[0], C = c[0];
    int matrix_a[R][C], matrix_b[R][C], matrix_c[R][C];
    scan_matrix_elements(R, C, matrix_a, 1);
    scan_matrix_elements(R, C, matrix_b, 2);
    print_matrix_elements(R, C, matrix_a, 1);
    print_matrix_elements(R, C, matrix_b, 2);
    print_add_matrix_elements(R, C, matrix_a, matrix_b);
    save_add_matrix_elements(R, C, matrix_a, matrix_b, matrix_c);
    print_matrix_elements(R, C, matrix_c, 3);
    return 0;
}
