#include "multitest.h"
#include <sys/time.h>

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

int main(int argc, char* argv[]){
        testA();
        testB();
        testC();
        testD();
}

void testA(){
    long timeArray[100];
    struct timeval start, end;
    int* array = giveMeARandomArray(100000);
    printf("Running Test A which searches a 100,000 elelement array for the number 15,200\n");    
    int i = 0;
    for(i=0;i<100;i++){
            gettimeofday(&start, NULL);
            int found = performSearch(array, 100000, 15200, 250);
            gettimeofday(&end, NULL);
            long seconds = end.tv_sec - start.tv_sec;
            timeArray[i] = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Ran iteration %d which took %d ms\n", (i+1), timeArray[i]);
            array = swapFoundWithRandom(array, found, 100000);
    }
    getMetrics(timeArray, 100, "Test A");
}
void testB(){
    long timeArray[100];
    struct timeval start, end;
    int* array = giveMeARandomArray(50000);
    printf("Running Test B which searches a 50,000 elelement array for the number 15,200\n");    
    int i = 0;
    for(i=0;i<100;i++){
            gettimeofday(&start, NULL);
            int found = performSearch(array, 50000, 15200, 250);
            gettimeofday(&end, NULL);
            long seconds = end.tv_sec - start.tv_sec;
            timeArray[i] = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Ran iteration %d which took %d ms\n", (i+1), timeArray[i]);
            array = swapFoundWithRandom(array, found, 50000);
    }
    getMetrics(timeArray, 100, "Test B");
}
void testC(){
    long timeArray[100];
    struct timeval start, end;
    int* array = giveMeARandomArray(10000);
    printf("Running Test C which searches a 10,000 elelement array for the number 200\n");    
    int i = 0;
    for(i=0;i<100;i++){
            gettimeofday(&start, NULL);
            int found = performSearch(array, 10000, 200, 250);
            gettimeofday(&end, NULL);
            long seconds = end.tv_sec - start.tv_sec;
            timeArray[i] = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Ran iteration %d which took %d ms\n", (i+1), timeArray[i]);
            array = swapFoundWithRandom(array, found, 10000);
    }
    getMetrics(timeArray, 100, "Test C");
}
void testD(){
    long timeArray[100];
    struct timeval start, end;
    int* array = giveMeARandomArray(1000);
    printf("Running Test D which searches a 1,000 elelement array for the number 200\n");    
    int i = 0;
    for(i=0;i<100;i++){
            gettimeofday(&start, NULL);
            int found = performSearch(array, 1000, 200, 250);
            gettimeofday(&end, NULL);
            long seconds = end.tv_sec - start.tv_sec;
            timeArray[i] = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Ran iteration %d which took %d ms\n", (i+1), timeArray[i]);
            array = swapFoundWithRandom(array, found, 1000);
    }
    getMetrics(timeArray, 100, "Test D");
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

void getMetrics(long array[], int size, char* testName){
    float stdArray[size];
    long min = array[0]; 
    long max = array[0];
    int i = 0;
    for(i = 0;i<size; i++){
            if(array[i]<min){
                    min = array[i];
            }else if(array[i]> max){
                    max = array[i];
            }
    }
    float average = getAvgLong(array, size);
    for(i = 0;i<size;i++){
            long num = array[i];
            float newNum = pow((num-average), 2);
            stdArray[i] = newNum;
    }
    float stdAverage = getAvgFloat(stdArray, size);
    float stdDev = sqrt(stdAverage);
    printf("For %s the average is %f ms, the min is %d ms, the max is %d ms, and the standard deviation is %f ms\n", testName, average, min, max, stdDev);
    return;
}

float getAvgFloat(float array[], int size){
    float average = 0;
    int i;
    float total =0;
    for(i = 0;i<size; i++){
            total += array[i];
    }
    average = total/size;
    return average;
}

float getAvgLong(long array[], int size){
    float average = 0;
    int i;
    float total =0;
    for(i = 0;i<size; i++){
            total += (float)array[i];
    }
    average = total/size;
    return average;
}













