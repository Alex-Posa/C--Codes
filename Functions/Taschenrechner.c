#include <stdio.h>
#include <math.h>

void berechnung(int z1, int operand, int z2){

    while(z1 != 0 && operand != 0 && z2 != 0){

        switch (operand)
        {
        case 0:
            printf("%d + %d = %d", z1, z2, z1+z2);
            break;

        case 1:
            printf("%d - %d = %d", z1, z2, z1-z2);
            break;

        case 2:
            if(z2 != 0)
            {
            printf("%d / %d = %.2lf", z1, z2, z1/z2);
            break;
            } else
            {
                printf("Nullteilung nicht moeglich!");
                 break;
            }

        case 3:
            printf("%d %% %d = %d Rest %d", z1, z2, z1/z2, z1%z2);
            break;

        case 4:
            printf("%d * %d = %d", z1, z2, z1*z2);
            break;
            
        case 5:
            if(z1 > 0 && z2 > 0)
            {
            printf("%d hoch %d = %lf", z1, z2, pow((double)z1,(double)z2));
            break;
            }
            else if(z2 < 0)
            {
                printf("%d hoch %d = 1/%.0lf", z1, z2, (1/pow((double)z1, (double)z2)));
                break;
            }
            else
            {
                printf("Negative Basis!");
                break;
            }
            

        default:
            printf("Ungueltige Operationseingabe!");
            break;
        }

        printf("\nWeitere Zahlen eingeben: ");
        printf("\nFuer Abbruch 0 0 0 eingeben.\n");
        printf("\nZahl 1: ");
        scanf("%d", &z1);

        printf("\nZahl 2: ");
        scanf("%d", &z2);

        printf("\nOperand: ");
        scanf("%d", &operand);
    }
}


void main(){

    int zahl1,zahl2;
    int operand;

    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &zahl1);

    printf("\nBitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &zahl2);


    printf("\nErlaubte Operationen:\n");
    printf("0.Addition\n1.Subtraktion\n2.Division\n3.Modulo\n4.Multiplikation\n5.Potenz");


    printf("\nBitte gewuenschte Operation eingeben: ");
    scanf("%d", &operand);

    berechnung(zahl1, operand, zahl2);

}
