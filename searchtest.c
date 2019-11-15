#include "multitest.h"

int* giveMeARandomArray(int size);
void printArray(int* array, int size);


int main(int argc, char* argv[]){
    int* array = giveMeARandomArray(10000);
    //printArray(array, 5000);
    performSearch(array, 20000, 242); 
}

int* giveMeARandomArray(int size){
    int* array = malloc((sizeof(int)) * size);
    int i =0;
    for(i = 0;i<size;i++){
            array[i] = i;
    }
    i = 0;
    for(i =0; i<size;i++){
            int n = rand() % (size);
            int k = rand() % (size);
            int temp = array[n];
            array[n] = array[k];
            array[k] = temp;
    }
    
    return array;
}

void printArray(int * array, int size){
        int i = 0;
        for(i = 0;i< size;i++){
                printf("Index %d is value: %d\n", i, array[i]);
        }
}
