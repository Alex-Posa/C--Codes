#include <stdio.h>
#include <stdlib.h>

#define NULL_ERROR 1

void quadrat(unsigned int u){
    int i,j;

    if(u==0){
        printf("Keine gueltige Angabe");
        exit(NULL_ERROR);
    }

    if(u==1){
        printf("*");
        exit(0);
    }

    //anfang
    for(i=0; i<u;i++){
        printf("*");
    }
    printf("\n");
    //mitte
    for(i=1; i<u-1;i++){
        for(j=0;j<u;j++){
            if(j!= u/2){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    //ende
    for(i=0; i<u;i++){
        printf("*");
    }


}


int main()
{
    int u;
    printf("Seitenlaenge des Quadrats: ");
    scanf("%d",&u);
    quadrat(u);

    return 0;
}
