#include <stdio.h>

int main(){
    double celcius, reamur, fahrenheit, kelvin;

    printf("This program take input Celcius Degreee and convert it into Reamur, Fahrenheit, and Kelvin\n");
    
    printf("Please input your Celcius Degree : ");
    scanf("%lf", &celcius);
    
    
    reamur = celcius * 4.0 / 5.0;
    fahrenheit = (celcius * 9.0 / 5.0) + 32;
    kelvin = celcius + 273.15;
    
    printf("\nYour celcius degree is : %.2lf", celcius);
    printf("\nYour reamur degree is : %.2lf", reamur);
    printf("\nYour fahrenheit degree is: %.2lf", fahrenheit);
    printf("\nYour kelvin degree is : %.2lf", kelvin);
    
    return 0;
}
