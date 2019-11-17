#include <stdio.h>
#include <stdlib.h>

//Flächenberechnung

int main(int argc, char* argv[])
{
   int Laenge, Hoehe, Flaeche;

   printf("Laenge: ");
   scanf("%d", &Laenge);
   printf("\nHoehe: ");
   scanf("%d", &Hoehe);
   Flaeche = Hoehe*Laenge;

   printf("\n----------\n");

   printf("Flaeche: %d", Flaeche);

    return 0;
}
