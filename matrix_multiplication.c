#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* BOLD_CYAN = "\033[1;36m";
const char* BOLD_YELLOW = "\033[1;33m";
const char* BOLD_MAGENTA = "\033[1;35m";
const char* BOLD_RED = "\033[1;31m";
const char* RESET = "\033[0m";

void print_cli_banner() {
    printf(
        "%s--------------------------------------------------------------------------------------------------------------------------------------%s\n"
        "%s"
        " ██████╗     ███╗   ███╗ █████╗ ████████╗██████╗ ██╗██╗  ██╗    ███╗   ███╗██╗   ██╗██╗  ████████╗██╗██████╗ ██╗      ██╗███████╗██████╗ \n"
        " ██╔════╝    ████╗ ████║██╔══██╗╚══██╔══╝██╔══██╗██║╚██╗██╔╝    ████╗ ████║██║   ██║██║  ╚══██╔══╝██║██╔══██╗██║      ██║██╔════╝██╔══██╗\n"
        " ██║         ██╔████╔██║███████║   ██║   ██████╔╝██║ ╚███╔╝     ██╔████╔██║██║   ██║██║     ██║   ██║██████╔╝██║      ██║█████╗  ██████╔╝\n"
        " ██║         ██║╚██╔╝██║██╔══██║   ██║   ██╔══██╗██║ ██╔██╗     ██║╚██╔╝██║██║   ██║██║     ██║   ██║██╔═══╝ ██║      ██║██╔══╝  ██╔══██╗\n"
        " ╚██████╗    ██║ ╚═╝ ██║██║  ██║   ██║   ██║  ██║██║██╔╝ ██╗    ██║ ╚═╝ ██║╚██████╔╝███████╗██║   ██║██║     ███████╗ ██║███████╗██║  ██║\n"
        "  ╚═════╝    ╚═╝     ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝    ╚═╝     ╚═╝ ╚═════╝ ╚══════╝╚═╝   ╚═╝╚═╝     ╚══════╝╚═╝╚══════╝╚═╝   ╚═╝ \n"
        "%s"
        "%s--------------------------------------------------------------------------------------------------------------------------------------%s\n\n"
        ,
        BOLD_YELLOW, RESET, BOLD_CYAN, RESET, BOLD_YELLOW, RESET
    );
    FILE *groups = fopen("../../groups.txt", "r");
    char buffer[100];
    printf("By:\n");
    for(int i = 0; i < 4; i++){
        fgets(buffer, 100, groups);
        size_t len = strlen(buffer);
        if(len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';
        printf("%s\n", buffer);
    }
    printf("\n\n");
    fclose(groups);
}

void scan_matrix_ordo(int r[2], int c[2]){
    FILE *inputFile = fopen("ordo.txt", "r");
    for(int i = 0; i < 2; i++){
        fscanf(inputFile, "%d %d", &r[i], &c[i]);
    }
    fclose(inputFile);
}

void print_matrix_ordo(int r[2], int c[2]){
    for(int i = 0; i < 2; i++){
        printf("%s[INFO]%s The ordo for matrix number %d is: %d x %d\n\n", BOLD_YELLOW, RESET, i + 1, r[i], c[i]);
    }
}

void check_valid_ordo(int r[2], int c[2]){
    if(c[0] == r[1]){
        printf("%s[INFO]%s We can continue to operate the multiplication for both matrices since both the size of collumn for matrix 1 is equal to the size of row matrix 2: %d == %d\n\n", BOLD_YELLOW, RESET,  c[0], r[1]);
    }else{
        printf("%s[WARNING]%s We can't continue to operate the multiplication for both matrices since both the size of collumn for matrix 1 is not equal to the size of row matrix 2: %d != %d\n\n", BOLD_RED, RESET, c[0], r[1]);
        exit(1);
    }
}

void scan_matrix_elements(int R, int C, int matrix[R][C], int matrix_num){
    FILE *inputFile = fopen(matrix_num == 1 ? "matrix_1.txt" : "matrix_2.txt", "r");
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            fscanf(inputFile, "%d", &matrix[i][j]);
        }
    }
    fclose(inputFile);
}

void print_matrix_elements(int R, int C, int matrix[R][C], int matrix_num){
    printf("%s[INFO]%s Print elements for matrix number %d\n", BOLD_YELLOW, RESET, matrix_num);
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int get_multiple(int a, int b){
    return a * b;
}

void save_result_matrix(int R, int C, int K, int res[R][C], int a[R][K], int b[K][C]){
    FILE *outputFile = fopen("output.txt", "w");
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            int res = 0;
            for(int k = 0; k < K; k++){
                res += get_multiple(a[i][k], b[k][j]);
            }
            fprintf(outputFile, "%d ", res);
        }
        fprintf(outputFile, "\n");
    }
    printf("%s[INFO]%s The result already been saved at output.txt\n", BOLD_YELLOW, RESET);
}


int main(){
    print_cli_banner();
    int r[2], c[2];
    scan_matrix_ordo(r, c);
    print_matrix_ordo(r, c);
    check_valid_ordo(r, c);
    int matrix_1[r[0]][c[0]], matrix_2[r[1]][c[1]], matrix_result[r[0]][c[1]];
    scan_matrix_elements(r[0], c[0], matrix_1, 1);
    scan_matrix_elements(r[1], c[1], matrix_2, 2);
    print_matrix_elements(r[0], c[0], matrix_1, 1);
    print_matrix_elements(r[1], c[1], matrix_2, 2);
    save_result_matrix(r[0], c[1], r[1], matrix_result, matrix_1, matrix_2);
    return 0;
}
