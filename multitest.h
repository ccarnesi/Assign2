#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

typedef struct threadStruct{
        int size;
        int key;
        int* array;
        int startIndex;
        int endIndex;
} threadStruct;

//thread function headers
int performSearch(int * array, int size, int key);

#endif
