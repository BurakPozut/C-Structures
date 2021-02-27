#include <stdio.h>
#include <stdlib.h>
#define K 7

void zero(int arr[][K]){			//It equal all the matrix to the zero
	int i,j;
	for(i=1;i<=K;i++)
		for(j=1;j<=K;j++)
			arr[i][j] = 0;
}

void addEdge(int arr[][K],int i,int j){			//Makeing the edges betweenthe nodes we want
	arr[i][j] = 1;
	arr[i][j] = 1;
}

void printMatrix(int arr[][K]){
	int i,j;
	
	for(i=1;i<=K;i++){
		printf("%d:",i);
		for(j=1;j<=K;j++){
			printf("%d",arr[i][j]);
			printf("\t");
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	int z;					// I added this part just for the sake of understandability of the out put
	printf("X:");
	for(z=1;z<=K;z++){
		printf("%d\t",z);
	}
	printf("\n");
	
	
	int adjMatrix[K][K];
	
	zero(adjMatrix);
	addEdge(adjMatrix,1,2);
	addEdge(adjMatrix,1,3);
	addEdge(adjMatrix,1,4);
	addEdge(adjMatrix,2,4);
	addEdge(adjMatrix,2,5);
	addEdge(adjMatrix,3,6);
	addEdge(adjMatrix,4,3);
	addEdge(adjMatrix,4,6);
	addEdge(adjMatrix,4,7);
	addEdge(adjMatrix,5,4);
	addEdge(adjMatrix,5,7);
	addEdge(adjMatrix,7,6);

	printMatrix(adjMatrix);
	
	return 0;
}
