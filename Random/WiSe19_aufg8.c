#include <stdio.h>
#include <stdlib.h>

double average(int a, int b, int c){
return (a+b+c)/3;
}



int main()
{
    int num1,num2,num3;

    printf("Please enter the first number: ");
    scanf("%d", &num1);

    printf("\nPlease enter the second number: ");
    scanf("%d", &num2);

    printf("\nPlease enter the third number: ");
    scanf("%d", &num3);

    printf("%.2lf",average(num1,num2,num3));

    return 0;
}
