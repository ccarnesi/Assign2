#include "multitest.h"


void* threadSearch(void* args){
    threadStruct* threadArgs = args;
    int* retValue = malloc(sizeof(int));
    *retValue = -1;
    int i = 0;
    int* array = threadArgs->array;
    for(i = 0;i<threadArgs->size;i++){
            if(array[i]==threadArgs->key){
                    //found
                    *retValue = i;
                    return (void*) retValue;
            }
    }
    return (void*) retValue;
}

int performSearch(int* array, int size, int key){
        int numberOfThreads = (int) ceil((double)size/(double)250);
        printf("Number Of Threads: %d\n", numberOfThreads);
        pthread_t threadArray[numberOfThreads];
        int* foundIndex  = malloc(sizeof(int));
        *foundIndex = -1;
        //init args to be passed
        threadStruct* threadArgs = malloc(sizeof(threadStruct)* 1);
        threadArgs->array = array;
        threadArgs->size = size;
        threadArgs->key = key;
        //init attr struct
        pthread_attr_t attrStruct; 
        pthread_attr_init(&attrStruct);
        //start creation process
        int i = 0;
        printf("Got to creation\n");
        for(i = 0;i<numberOfThreads;i++){
                pthread_create(&threadArray[i], &attrStruct, threadSearch, (void*)threadArgs);
        }

        //wait for threads
        i =0;
        for(i = 0;i<numberOfThreads;i++){
                pthread_join(threadArray[i], (void**)&foundIndex);
                if(*foundIndex != -1){
                        printf("Found at index %d\n", *foundIndex + (250*(i)));
                        break;
                }
        }
        return 0;
}


