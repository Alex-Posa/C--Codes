#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    double n1,n2;
    char o;

    printf("Zahl1: ");
    scanf("%lf",&n1);
    printf("\nRechenoperator: ");
    scanf(" %c", &o);
    printf("\nZahl2: ");
    scanf("%lf", &n2);

    switch(o){
        case '+':
            printf("%.2lf + %.2lf = %.2lf", n1,n2,n1+n2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf", n1,n2,n1-n2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf", n1,n2,n1*n2);
            break;
        case '/':
            printf("%.2lf / %.2lf = %.2lf", n1,n2,n1/n2);
            break;

        default: printf("Keine gueltige Eingabe.");
            break;
    }

    return 0;
}
