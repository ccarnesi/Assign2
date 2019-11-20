#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <sys/wait.h>

typedef struct threadStruct{
        int size;
        int key;
        int* array;
        int startIndex;
        int endIndex;
} threadStruct;

//thread function headers
int performSearch(int * array, int size, int key, int blockSize);
#define Search(X, Y, Z, Q) performSearch(X, Y, Z, Q)
int* giveMeARandomArray(int size);
void printArray(int* array, int size);
int* swapFoundWithRandom(int* array, int index, int size);
float getAvgFloat(float array[], int size);
float getAvgLong(long array[], int size);
void getMetrics(long array[], int size, char* testName);

void testA();
void testB();
void testC();
void testD();
void testE();
void testF();
void testG();
void testH();
void testI();
void testJ();
void testMeep();

#endif
