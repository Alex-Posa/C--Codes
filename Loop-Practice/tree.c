#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int nummer= argv[0],j,i;
    int leerzeichen = 3*nummer/2;
    int stern;

    /*printf("Geben sie die Anzahl der Aeste an: ");
    scanf("%d", &nummer);*/

    for(i=0, stern=1; i < nummer*3; i++, stern=stern+2){

        if(i%3==0 && i!=0){

            leerzeichen +=2;
            stern -= 4;
        }
        for(j=0; j<leerzeichen-i;j++){
            printf(" ");
        }

        for(j=0; j<stern; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
