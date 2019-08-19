#include <stdio.h>


int mystrl_length(char string[100], int length){

    int i=0;
    while(string[i] != '\0')
        i++;

    return i;
}

void caesar_chiffre(char array[],int chiffre){

    int i;
    for(i=0; i < mystrl_length(array,100); i++){
        if(array[i] == 'Y'|| array[i] == 'y'|| array[i] == 'Z'|| array[i] == 'z'){
        array[i] = array[i]-26;
        }
        printf("%c",array[i]+chiffre);
    }


}



int main()
{
    int Schluessel = 3;
    char array[100] = {"nYcz"};
    //printf("Geben Sie einen Schluessel ein: ");
    //scanf("%d",&Schluessel);

    caesar_chiffre(array,Schluessel);

  return 0;
}
