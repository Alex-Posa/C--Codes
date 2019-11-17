#include <stdio.h>
#include <stdlib.h>

void isPrimeNumber(int x){

    int i,c=0;
    for(i=1; i<=x; i++){
        if(x%i == 0){
            c++;
        }
    }

    if(c == 2){
        printf("Ist eine Primzahl");
    }
    if( c < 2 || c > 2){
        printf("Ist keine Primzahl");
    }
}


int main(int argc, char* argv[])
{
    int n;
    printf("Zahl: ");
    scanf("%d",&n);

    isPrimeNumber(n);



    return 0;
}
