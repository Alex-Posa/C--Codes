#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double berechneFlaeche(double r){
    double flaeche;
    flaeche = M_PI * (r * r);
    return flaeche;
}

int main(int argc, char* argv[])
{
    double radius;
    printf("\tFLAECHENBERECHNUNG EINES KREISES\t");
    printf("\n---------------------------------------------------------\n");

    printf("Radius: ");
    scanf("%lf", &radius);
    printf("Flaeche des Kreises: %.2lf",berechneFlaeche(radius));

    return 0;
}
