#include "multitest.h"
int performSearch(int * array , int size, int key, int blocksize){
 /*If we are able to get the number of forks that we have to do then we can also somehow pass the other two numbers but not sure how (basically create method that will allow us*/
	int blocks =size/ blocksize;
	int remainder = 0;
	remainder = size % blocksize;
	if(remainder> 0){
		blocks++;
	}
	int i,init=0,start=0,child= 0;
	int fin = blocksize;
	int status,number;
	int children[blocks];
	int found = -1;
	for(i=0;i <blocks;i++){
		/*this is the loop that will create the necessary amount of children, just have to figure out a way to be able to iterate through the array in the correct positions*/
		int id = fork();
		//printf("at iteration %d, and id of child/parent is %d\n",i, id);
		if(id==0){
			//printf("start is %d, end is %d \n",start, fin);
			int counter = start;
			int count =0;
			for(counter; counter<fin;counter++){
				if(array[counter]==key){
					//printf("found keey at %d and iteration %d \n",count, i);
					exit(count);
				}
				++count;
			}
			exit(254);
		}
		else{
			/*here we know that we are the parent so we gotta increase our increments for blocks while also adding the return value of fork into our array of child id's*/
			start += blocksize;
			fin += blocksize;
			if(i==blocks-1){
				fin = size;
			}
			children[i] = id;
			//printf("added id of %d, \n",id);

		}
	}
		/*here parent waits on all children*/
	pid_t cpid;
	for(i=0;i<blocks;i++){
		cpid = wait(&status);	
		//printf("at the waiting stage with cpid of %d cpid");
		if(WIFEXITED(cpid)){
		//	printf("exited normally\n");
			if(WEXITSTATUS(status)!=254){
				int lala =0;
				for(lala=0;lala<blocks;lala++){
					if(children[lala] == cpid){
						break;
					}
				}
				//printf("lala is %d, block size is %d, stat is %d\n",i,blocksize,WEXITSTATUS(status));
				found = (i*blocksize)+WEXITSTATUS(status);
				//printf("our number that we are checking with is %d \n",found);
			}
		}
			else{
			//	printf("not found in this iteration\n");
			}
	}
					

	
		return found;

		
}	
