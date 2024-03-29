#include "multitest.h"
#include <sys/time.h>

int main(int argc, char* argv[]){
	testJ();
	testD();
	testE();
	testC();
	testB();
}
void testB(){
	long timeArray[100];
	struct timeval start, end;
	int * array = giveMeARandomArray(15000);
	printf("Running Test B which searches a 15,000 element array for the number 200\n");
	int i =0;
	for(i=0;i<100;i++){
		gettimeofday(&start,NULL);
		int found = Search(array,15000,200,250);
		gettimeofday(&end,NULL);
        printf("Ran iteration %d\n", (i+1));
		long seconds = end.tv_sec-start.tv_sec;
		timeArray[i] = ((seconds * 1000000) + end.tv_usec) -(start.tv_usec);
		array = swapFoundWithRandom(array,found,15000);
	}
	//float avg = getAvgLong(timeArray,100);
	//printf("%d,%f\n",15000,avg);
	 getMetrics(timeArray,100, "Test B");
}

void testC(){
    long timeArray[100];
    struct timeval start, end;
    int* array = giveMeARandomArray(10000);
    printf("Running Test C which searches a 10,000 element array for the number 200\n");    
    int i = 0;
    for(i=0;i<100;i++){
            gettimeofday(&start, NULL);
            int found = Search(array, 10000, 200, 250);
            gettimeofday(&end, NULL);
            long seconds = end.tv_sec - start.tv_sec;
            timeArray[i] = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
      	    printf("Ran iteration %d\n", (i+1));
            array = swapFoundWithRandom(array, found, 10000);
    }
    //float avg = getAvgLong(timeArray, 100);
    //printf("%d,%f\n",10000, avg);

   getMetrics(timeArray, 100, "Test C");
}
void testD(){
    long timeArray[100];
    struct timeval start, end;
    int* array = giveMeARandomArray(1000);
    printf("Running Test D which searches a 1,000 element array for the number 200\n");    
    int i = 0;
    for(i=0;i<100;i++){
            gettimeofday(&start, NULL);
            int found = Search(array, 1000, 200, 250);
            gettimeofday(&end, NULL);
            long seconds = end.tv_sec - start.tv_sec;
            timeArray[i] = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Ran iteration %d\n", (i+1));
            array = swapFoundWithRandom(array, found, 1000);
    }
    //float avg = getAvgLong(timeArray, 100);
    //printf("%d,%f\n",1000, avg);
    getMetrics(timeArray, 100, "Test D");
}

void testE(){
    long timeArray[100];
    struct timeval start, end;
    int* array = giveMeARandomArray(5000);
    printf("Running Test E which searches a 5,000 element array for the number 200 in chunks of 250\n");    
    int i = 0;
    for(i=0;i<100;i++){
            gettimeofday(&start, NULL);
            int found = Search(array, 5000, 200, 250);
            gettimeofday(&end, NULL);
            long seconds = end.tv_sec - start.tv_sec;
            timeArray[i] = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Ran iteration %d\n", (i+1));
            array = swapFoundWithRandom(array, found, 5000);
    }
    //float avg = getAvgLong(timeArray, 100);
    //printf("%d,%f\n",250, avg);
    getMetrics(timeArray, 100, "Test E");
}
void testF(){
    long timeArray[100];
    struct timeval start, end;
    int* array = giveMeARandomArray(5000);
    printf("Running Test F which searches a 5,000 element array for the number 200 in chunks of 150\n");    
    int i = 0;
    for(i=0;i<100;i++){
            gettimeofday(&start, NULL);
            int found = Search(array, 5000, 200, 150);
            gettimeofday(&end, NULL);
            long seconds = end.tv_sec - start.tv_sec;
            timeArray[i] = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Ran iteration %d\n", (i+1));
            array = swapFoundWithRandom(array, found, 5000);
    }
    //float avg = getAvgLong(timeArray, 100);
    //printf("%d,%f\n",150, avg);
    getMetrics(timeArray, 100, "Test F");
}
void testG(){
    long timeArray[100];
    struct timeval start, end;
    int* array = giveMeARandomArray(5000);
    printf("Running Test G which searches a 5,000 element array for the number 200 in chunks of 50\n");    
    int i = 0;
    for(i=0;i<100;i++){
            gettimeofday(&start, NULL);
            int found = Search(array, 5000, 200, 50);
            gettimeofday(&end, NULL);
            long seconds = end.tv_sec - start.tv_sec;
            timeArray[i] = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Ran iteration %d\n", (i+1));
            array = swapFoundWithRandom(array, found, 5000);
    }
    //float avg = getAvgLong(timeArray, 100);
    //printf("%d,%f\n",50, avg);

    getMetrics(timeArray, 100, "Test G");
}

void testH(){
    long timeArray[100];
    struct timeval start, end;
    int* array = giveMeARandomArray(5000);
    printf("Running Test H which searches a 5,000 element array for the number 200 in chunks of 10\n");    
    int i = 0;
    for(i=0;i<100;i++){
            gettimeofday(&start, NULL);
            int found = Search(array, 5000, 200, 10);
            gettimeofday(&end, NULL);
            long seconds = end.tv_sec - start.tv_sec;
            timeArray[i] = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Ran iteration %d\n", (i+1));
            array = swapFoundWithRandom(array, found, 5000);
    }
    //float avg = getAvgLong(timeArray, 100);
    //printf("%d,%f\n",10, avg);

    getMetrics(timeArray, 100, "Test H");
}

void testI(){
    long timeArray[100];
    struct timeval start, end;
    int* array = giveMeARandomArray(5000);
    printf("Running Test I which searches a 5,000 element array for the number 200 in chunks of 5\n");    
    int i = 0;
    for(i=0;i<100;i++){
            gettimeofday(&start, NULL);
            int found = Search(array, 5000, 200, 5);
            gettimeofday(&end, NULL);
            long seconds = end.tv_sec - start.tv_sec;
            timeArray[i] = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Ran iteration %d \n", (i+1));
            array = swapFoundWithRandom(array, found, 5000);
    }
    //float avg = getAvgLong(timeArray, 100);
    //printf("%d,%f\n",5, avg);
    getMetrics(timeArray, 100, "Test I");
}

void testJ(){
    long timeArray[100];
    struct timeval start, end;
    int* array = giveMeARandomArray(250);
    printf("Running Test J which searches a 250 element array for the number 200\n");    
    int i = 0;
    for(i=0;i<100;i++){
            gettimeofday(&start, NULL);
            int found = Search(array, 250, 200, 250);
            gettimeofday(&end, NULL);
            long seconds = end.tv_sec - start.tv_sec;
            timeArray[i] = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
            printf("Ran iteration %d\n", (i+1));
            array = swapFoundWithRandom(array, found, 250);
    }
    //float avg = getAvgLong(timeArray, 100);
    //printf("%d,%f\n",250, avg);

    getMetrics(timeArray, 100, "Test J");
}

void testFirstMeep(){
	long timeArray[100];
	struct timeval start, end;
	int arraySizes[] = {1000, 5000, 10000, 15000, 20000};
	int* array; 
	int i,j = 0;
	for(i=0;i<5;i++){
        array = giveMeARandomArray(arraySizes[i]);
        printf("Running Test First Meep on array size %d", arraySizes[i]);
		for(j=0;j<100;j++){
			gettimeofday(&start,NULL);
			int found = Search(array,arraySizes[i],200,250);
			gettimeofday(&end, NULL);
            printf("Ran iteration %d\n", (i+1));
			long seconds = end.tv_sec - start.tv_sec;
			timeArray[j] = ((seconds*1000000) + end.tv_usec)-(start.tv_usec);
			array = swapFoundWithRandom(array,found,arraySizes[i]);
		}
        getMetrics(timeArray, 100, "Test First Meep");
        //float average = getAvgLong(timeArray,100);
	    //printf("%d,%f\n",arraySizes[i],average);
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












