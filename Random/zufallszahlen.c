#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define SUCCESS 0
#define SIZE 200


void print_array(int* array){

    int counter = 0;

     for(int j = 0; j < SIZE; j++){
        printf("%d\n", array[j]);
        counter++;
    }

    printf("\n\nCounter: %d\n", counter);

}


void bubblesort(int* array){

    int i,j,tmp;

    for(i = 1; i < SIZE; i++){
        for(j = 0; j < SIZE-i; j++){
            if(array[j] > array[j+1] ){
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
    print_array(array);
}


int main(int argc, char* argv[]){

     static int randArray[SIZE];
    srand(time(NULL));
    

//generating random numbers and placing them into the array of size 200

    for(int i = 0; i < SIZE; i++){
        if(randArray[i] == randArray[SIZE]){
            randArray[i] = '\0';
        }

        randArray[i] = rand();
      
    }

//sorting the array with the random numbers with a bubble sort

bubblesort(randArray);

    return SUCCESS;
}
