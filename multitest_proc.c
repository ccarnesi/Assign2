#include <math.h>
int procSearch(int * array , int size, int key, int blocksize){
 /*If we are able to get the number of forks that we have to do then we can also somehow pass the other two numbers but not sure how (basically create method that will allow us*/
	int blocks =size/ blocksize;
	int times = log2(blocks);
	int i,init,start= 0;
	int fin = blocksize;
	int stat;
	for(i=0;i < blocks;i++){
		/*this is the loop that will create the necessary amount of children, just have to figure out a way to be able to iterate through the array in the correct positions*/
		if(fork()==0){
			/*at child and should change what area to search*/
			start += blocksize;
			fin += blocksize;
			if(i==blocks-1){
				finish =size;
			}
			counter = start;
			count = 0;
			/*this portion searches for the key*/
			for(counter; counter<finish;start++){
				if(array[counter]==key){
					exit(count);

				}
				++count;
			}
			/*reached end of assigned area of array*/
			exit(255);
		}
		else{
			/*here the parent is waiting for the child and recieved the number in which they found the key*/
			wait(&stat)
		}
		/* here 255 means child found no key in their array search*/
		if(WIFEXITED(stat)){
			if(WEXITSTATS(stat)==255){
				/*not found in that child process continue*/
				continue;
			}
			else{
				/*found somewhere*/
				return (i*blocksize)+WEXITSTATS(stat)

			}
		}

	}
	return -1
}	
