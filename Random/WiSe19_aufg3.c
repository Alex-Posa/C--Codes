#include <stdio.h>
#include <stdlib.h>


double toSquare(double number){
    return number*number;
}

int main(int argc, char* argv[])
{
   double ankathete,gegenkathete, hypotenuse;

   printf("Ankathete: ");
   scanf("%lf",&ankathete);
   toSquare(ankathete);
   printf("Gegenkathete: ");
   scanf("%lf", &gegenkathete);
   toSquare(gegenkathete);

   hypotenuse = ankathete+gegenkathete;
   printf("Hypotenuse: %.2lf", hypotenuse);





    return 0;
}
