#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100

void list_current_directory(){
    printf("Available Files & Directories (Using system command)\n");
    #ifdef _WIN32
        int status = system("dir /B");
    #else
        int status = system("ls -la");
    #endif
    if(status != 0){
        printf("\nWarning: Could not execute the system command to list files. Status code: %d\n", status);
    }
    printf("Listing available current files & directories is finished\n\n");
}

int main(){
    FILE *fp = NULL;
    char filename[MAX_FILENAME_LEN];
    int num1, num2;
    list_current_directory();
    if(fp == NULL){
        printf("Please enter the name of the file you want to open: ");
        if(fgets(filename, MAX_FILENAME_LEN, stdin) == NULL){
            printf("Error reading input. Exiting.\n");
            return 1;
        }
        size_t len = strlen(filename);
        if(len > 0 && filename[len - 1] == '\n'){
            filename[len - 1] = '\0';
        }
        if(len == 0){
            printf("Filename cannot be empty. Exiting,\n");
            return 1;
        }
        fp = fopen(filename, "r");
        if(fp == NULL){
            perror("Error opening file");
            printf("File '%s' could not be opnened, Please check the name and path.\n\n", filename);
            return 1;
        }
    }
    if(fscanf(fp, "%d", &num1) == 1){
        printf("Successfully read first integer: %d\n", num1);
    }else{
        printf("Could not read the first integer.\n");
    }
    if(fscanf(fp, "%d", &num2) == 1){
        printf("Successfully read second integer: %d\n", num2);
    }else{
        printf("Could not read the second integer.\n");
    }
    printf("The addition between two numbers are: %d", num1 + num2);
    return 0;
}
