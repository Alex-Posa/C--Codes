#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN 50

typedef struct{
    char name[ARR_LEN];
    char vorname[ARR_LEN];
    char strasse[ARR_LEN];
    int  plz;
    char ort[ARR_LEN];

}patient;



int main()
{
    int i = 0, j;
    patient pt[4];

    printf("Bitte die Patientendaten eingeben.\n\n");

  do{

    printf("\nName des Patienten: ");
    scanf("%s", pt[i].name);
    printf("\nVorname des Patienten: ");
    scanf("%s", pt[i].vorname);
    printf("\nStrasse des Patienten: ");
    scanf("%s", pt[i].strasse);
    printf("\nPostleitzahl des Patienten: ");
    scanf("%d", &pt[i].plz);
    printf("\nOrt des Patienten: ");
    scanf("%s", pt[i].ort);
    printf("\n\n");


    i++;
  } while(i < 4);

  for(j=0; j<4; j++){
    printf("Name: %s\n\Vorname: %s\n\Strasse: %s\n\PLZ: %d\n\Ort: %s\n", pt[j].name, pt[j].vorname, pt[j].strasse, pt[j].plz, pt[j].ort);
  }


    return 0;
}
