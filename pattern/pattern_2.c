#include <stdio.h>

int main(){
    int input, i = 0, increment = 1;
    printf("Please insert your input: ");
    scanf("%d", &input);

    while(i >= 0){
        for(int j = 0; j < input; j++) printf((i <= j ? "* " : "  "));
        printf("\n");
        if(i == input - 1) increment = -1;
        i += increment;
    }

    return 0;
}
