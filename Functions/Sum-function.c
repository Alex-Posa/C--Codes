#include <stdio.h>
#include <stdlib.h>


int summe(int a, int b){

return a+b;
}

void print_summe(int length){

    int i;
    for(i=0; i < length; i++){
        printf("* ");
    }

}


int main()
{
    int a = 5;
    int b = 5;


    printf("Die Summe aus %d und %d ist %d\n",a,b, summe(a,b));
    print_summe(summe(a,b));

    return 0;
}
