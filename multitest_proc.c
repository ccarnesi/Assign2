#include "multitest.h"
int performSearch(int * array , int size, int key, int blocksize){
 /*If we are able to get the number of forks that we have to do then we can also somehow pass the other two numbers but not sure how (basically create method that will allow us*/
	int blocks =size/ blocksize;
	int remainder = 0;
	remainder = size % blocksize;
	if(remainder> 0){
		blocks++;
	}
	int i,init,start,child= 0;
	int fin = blocksize;
	int stat;
	int children[blocks];
	int found = -1;
	for(i=0;i <blocks;i++){
		/*this is the loop that will create the necessary amount of children, just have to figure out a way to be able to iterate through the array in the correct positions*/
		int id = fork();
		if(id==0){
			child =1;
			break;
		}
		else{
			/*here we know that we are the parent so we gotta increase our increments for blocks while also adding the return value of fork into our array of child id's*/
			start += blocksize;
			fin += blocksize;
			if(i==blocks-1){
				fin = size;
			}
			children[i] = id;

		}
	}
	if(child ==1){
		int counter = start;
		int count =0;
		for(counter; counter<fin;counter++){
			if(array[counter]==key){
				exit(count);
			}
			++count;
		}
		exit(255);
	}
	else{
		/*here parent waits on all children*/
		for(i=0;i<blocks;i++){
			waitpid(children[i],&stat,WNOHANG);
			if(WIFEXITED(stat)){
				if(WEXITSTATUS(stat)!=255){
					found = (i*blocksize)+WEXITSTATUS(stat);
				}
					
			}
		}
		return found;

	}
		
}	
