#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node{
	int data;
	int *data2;
	struct Node* left,*right,*middle;
};
struct Node* newNode(int value,int *value2){			// New Node
	struct Node* newNode = malloc(sizeof(struct Node));

	if(value2 !=NULL){
		if(value > *value2){	// value value2 den büyük olursa deðerlerini deðiþtir
			int t;
			t = value;
			value = *value2;
			*value2 = t;
		}
	}
	newNode->data = value;
	newNode->data2 = value2;
	newNode->left = newNode->right = NULL;
	
	return newNode;
}
struct Node* multiValue(struct Node* n,int value,int *value2){				// Making a node multivalued
	if(value == n->data){
		struct Node* temp = malloc(sizeof(struct Node));
		if(value > *value2){	// value value2 den büyük olursa deðerlerini deðiþtir
			int t;
			t = value;
			value = *value2;
			*value2 = t;
		}
		temp->data = value;
		temp->data2 = value2;
		temp->right = n->right;
		temp->middle = n->middle;
		temp->left = n->left;
		free(n);
		return temp;
	}
		if(value > n->data && value > *n->data2)
			n->right = multiValue(n->right,value,value2);
		if(value < n->data)
			n->left = multiValue(n->left,value,value2);	
		if(value > n->data && value < *n->data2)
			n->middle = multiValue(n->middle,value,value2);
			
	
		return;
}

struct Node* Insert(struct Node* n,int value,int *value2){
	if(n == NULL){
		if(value2 == NULL){
			return newNode(value,NULL);
		}
		return newNode(value,value2);
	}
		
	if(value > n->data && value > *n->data2)
		n->right = Insert(n->right,value,value2);
	if(value < n->data)
		n->left = Insert(n->left,value,value2);
	if(value > n->data && value < *n->data2)
		n->middle = Insert(n->middle,value,value2);
		

}

void preOrder(struct Node* n){			// Pre-order 
	if(n != NULL){
		printf("%d\n",n->data);
		if(n->data2 != NULL)
			printf("%d\n",*n->data2);
		printf("\n");
		preOrder(n->left);
		preOrder(n->right);
	}
}


int main(int argc, char *argv[]) {
	struct Node* root =NULL;
	int i = 4,n=7;
	root = Insert(root,5,&i);
	Insert(root,15,NULL);
	Insert(root,1,NULL);
	
	multiValue(root,15,&n);
	
	preOrder(root);
	
	return 0;
}
