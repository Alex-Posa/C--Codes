#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s1, s2, erg;

    printf("Zahl 1: ");
    scanf("%d", &s1);

    printf("Zahl 2: ");
    scanf("%d", &s2);

    erg = s1 + s2;

    printf("\n\n    Adressen \n- - - - - - - - \n");
    printf("| s1: %p  |\n", &s1);
    printf("| s2: %p  |\n", &s2);
    printf("| erg: %p |\n", &erg);



    return 0;
}
