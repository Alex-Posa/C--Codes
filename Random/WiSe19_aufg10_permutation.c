#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change(char*, char*);

void permute(char* x, int start, int end){
    int i;
    if(start == end){
        printf("%s\n", x);
    } else {
        for(i=start; i<= end; i++ ){
            change((x+start),(x+i));
            permute(x, start+1, end);
            change((x+start),(x+i));
        }
    }

}

void change(char *x, char *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int main()
{
    char string[] = "abc";
    int stringlength = strlen(string);
    permute(string, 0, stringlength-1);

    return 0;
}
