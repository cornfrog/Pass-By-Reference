#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 5

void passInt(int** x);
void initializeArray(int** array);
void modifyArray(int** array);
void printArray(int** array);

int main(){
	int* x = NULL;
	int* testArray = NULL;
	//mallocing for 'x'
	x = (int*)malloc(sizeof(int));
	//checking 'x' malloc()
	if(x == NULL){
		printf("Error: Malloc Failed!\n");
		return 1;
	}
	//mallocing testArray
	testArray = (int*)malloc(ARR_SIZE * sizeof(int));
	//checking testArray malloc()
	if(testArray == NULL){
		printf("Error: Malloc Failed!\n");
		return 1;
	}
	
	//setting pointers to values
	*x = 5;
	initializeArray(&testArray);

	//printing information on int* x
	printf("Before Modifying Int:\n");
	printf("*x: %d\n", *x);
	printf("&x: %p\n", &x);
	printf("\n");
	passInt(&x);	//passing memory location of x
	printf("\n");
	printf("After Modifying Int:\n");
	printf("*x: %d\n", *x);
	printf("&x: %p\n", &x);
	printf("\n\n");
	//freeing x 
	free(x);
	x = NULL;
	if(x != NULL){
		printf("Error: Free Falied\n");
		return 1;
	}
	//end info on int* x
	
	//printing info on int* testArray
	printArray(&testArray);
	printf("\n");
	modifyArray(&testArray);
	printf("\n");
	printArray(&testArray);
	printf("\n");
	//freeing testArray
	free(testArray);
	testArray = NULL;
	if(testArray != NULL){
		printf("Error: Free Falied\n");
		return 1;
	}
	//end of info on int* testArray
	return 0;
}

void passInt(int** x){
	printf("Modifying Int:\n");
	printf("*x: %d\n", **x);
	printf("&x: %p\n", &(*x));
	(**x)++;
	printf("x Modified\n");
}

void initializeArray(int** array){
	for(int i = 0; i < ARR_SIZE; i++){
		(*array)[i] = i;
	}
}
	
void modifyArray(int** array){
	printf("Modifying Array\n");
	for(int i = 0; i < ARR_SIZE; i++){
		(*array)[i] *= 2;
	}
	printf("Done Modifying Array\n");
}

void printArray(int** array){
	printf("Printing Array:\n");
	printf("&array: %p\n", &array);
	printf("&(*array): %p\n", &(*array));
	printf("&(**array): %p\n", &(**array));
	for(int i = 0; i < ARR_SIZE; i++){
		printf("array[%d]: %d - %p\n", i, (*array)[i], &(*array)[i]);
	}
}
