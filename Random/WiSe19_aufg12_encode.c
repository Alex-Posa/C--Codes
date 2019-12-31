#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char string[], int key){
    int i;
    for(i=0; i< strlen(string); i++){
        if(string[i] == 'Y' || string[i] == 'y' || string[i] == 'Z' || string[i] == 'z'){
            string[i] = string[i]-26;
        }
        printf("%c", string[i]+key);
    }
}

int main()
{
    int key;
    printf("Enter the encode-key: ");
    scanf("%d", &key);

    char sentence[100] = {"Test to be encoded"};
    encode(sentence,key);

    return 0;
}
