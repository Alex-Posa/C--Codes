#include <stdio.h>
#include <stdlib.h>

int main()
{
    int decision;
    int sum = 0,num;
    printf("To start this program type a '1' below\n");
    scanf("%d", &decision);

    if(decision==0){
        printf("Not executing program.\n");
    }

    while(decision==1){
        if(decision==1){
            printf("Add next integer.\n");
            printf("Next number: ");
            scanf("%d",&num);
            if(num == 0){
                decision = 0;
                printf("The sum of the previous numbers is: %d", sum);
            }
            sum += num;
        }
    }



    return 0;
}
