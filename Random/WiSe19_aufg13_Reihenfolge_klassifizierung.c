#include <stdio.h>
#include <stdlib.h>

int main()
{
    int gerade=0, ungerade=0, null=0;
    int negativ=0, positiv=0;

    int eingabe,i=0;

    printf("Geben sie Ihre Zahlen ein: ");

    while(i < 5){
        scanf("%d", &eingabe);
        if(eingabe<0){
            negativ++;
            if(eingabe%2 != 0){
                ungerade++;
            } else {
                gerade++;
            }
        }

        if(eingabe>0){
            positiv++;
            if(eingabe%2 != 0){
                ungerade++;
            } else {
                gerade++;
            }
        }

        if(eingabe==0){
            null++;
        }
        i++;
    }

    printf("Zahlen die gerade waren: %d\n", gerade);
    printf("Zahlen die ungerade waren: %d\n", ungerade);
    printf("Nullziffer anzahl: %d\n", null);
    printf("Zahlen die negativ waren: %d\n", negativ);
    printf("Zahlen die positiv waren: %d\n", positiv);

    return 0;
}
