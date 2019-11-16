#include "multitest.h"

int* giveMeARandomArray(int size);
void printArray(int* array, int size);
int* swapFoundWithRandom(int* array, int index, int size);
void linearSearch();

void testA();

int main(int argc, char* argv[]){
        testA();
}

void testA(){
    int* array = giveMeARandomArray(50000);
    
    int i = 0;
    for(i=0;i<100;i++){
            int found = performSearch(array, 50000, 15200);
            array = swapFoundWithRandom(array, found, 50000);
    }

}


int* swapFoundWithRandom(int* array, int index, int size){
    int k = rand() % size;
    int temp = array[k];
    array[k] = array[index];
    array[index] = temp;
    return array;
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
