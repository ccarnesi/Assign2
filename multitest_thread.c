#include "multitest.h"

void freeThreadArray(threadStruct* argArray[], int size);

void* threadSearch(void* args){
    threadStruct* threadArgs = args;
    int* retValue = malloc(sizeof(int));
    *retValue = -1;
    int i = 0;
    int* array = threadArgs->array;
    for(i = threadArgs->startIndex;i<threadArgs->endIndex;i++){
            if(array[i]==threadArgs->key){
                    //found
                    *retValue = i;
                    //return (void*) retValue;
                    pthread_exit(retValue);
            }
    }
     pthread_exit(retValue);
     //return (void*)retValue;
}


int performSearch(int* array, int size, int key, int blockSize){
//        printf("Searching using multi-threading\n");
        int numberOfThreads = (int) ceil((double)size/(double)blockSize);
        pthread_t threadArray[numberOfThreads];
        int* foundIndex  = malloc(sizeof(int));
        *foundIndex = -1;
        //init args to be passed
        threadStruct* argArray[numberOfThreads];
        int k =0;
        for(k=0;k<numberOfThreads;k++){
            threadStruct* threadArgs = malloc(sizeof(threadStruct)* 1);
            threadArgs->array = array;
            threadArgs->size = size;
            threadArgs->key = key;
            threadArgs->startIndex = blockSize*k;
            if(threadArgs->startIndex + blockSize-1< size-1){
                    threadArgs->endIndex = threadArgs->startIndex + blockSize;
            }else{
                    threadArgs->endIndex = size;
            }
            argArray[k] = threadArgs;
        }
        //init attr struct
        pthread_attr_t attrStruct; 
        pthread_attr_init(&attrStruct);
        //start creation process
        int i = 0;
        for(i = 0;i<numberOfThreads;i++){
                pthread_create(&threadArray[i], &attrStruct, threadSearch, (void*)argArray[i]);
        }

        //wait for threads
        i =0;
        for(i = 0;i<numberOfThreads;i++){
                pthread_join(threadArray[i], (void**)&foundIndex);
                if(*foundIndex != -1){
                        i++;
                        while(i<numberOfThreads){
                                pthread_join(threadArray[i], NULL);
                                i++;    
                        }
                        break;
                }
        }
        //free all the threads;
        freeThreadArray(argArray, numberOfThreads);
        return *foundIndex;
}

void freeThreadArray(threadStruct* argArray[], int size){
        int i =0;
        for(i=0;i<size;i++){
                free(argArray[i]);
        }
        return;
}
