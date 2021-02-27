#include <stdio.h>
#include <stdlib.h>
/* 
Pre-order Traversal
	14 ,4 ,3 ,9 ,7 ,5 ,4 ,5 ,9 ,15 ,14 ,18 ,16 ,17 ,20
Post-order Traversal
	3 ,4 ,5 ,5 ,7 ,9 ,9 ,4 ,14 ,17 ,16 ,20 ,18 ,15 ,14
In-order Traversal
	3 ,4 ,4 ,5 ,5 ,7 ,9 ,9 ,14 ,14 ,15 ,16 ,17 ,18 ,20
*/
struct Node {
	int data;
	struct Node *left,*right;
};

struct Node* newNode(int value){				// New Node
	struct Node* NewNode = malloc(sizeof(struct Node));
	NewNode->data = value;
	NewNode->left = NewNode->right = NULL;
	return NewNode;
}

void Find(struct Node* n,int value){			// Find

	while(n != NULL){
		if(n->data > value)
		n = n->left;
		
		else if(n->data < value)
		n = n->right;
		
		else{
		printf("Node is exist");
		return;
		}
		
	}
	printf("Node is not exist");
	return;
}

struct Node* minValue(struct Node* n){				//Min Value
	
	while(n && n->left != NULL)
		n = n->left;
		
	return n;
}
struct Node* deleteNode(struct Node* n,int value){			// Delete Node
	
	if(n == NULL) return n;
	
	if(value < n->data)
		n->left = deleteNode(n->left,value);
		
	else if(value > n->data)
		n->right = deleteNode(n->right,value);
		
	else{
		if(n->left == NULL){
			struct Node* temp = n->right;
			free(n);
			return temp;
		}
		else if(n->right == NULL){
			struct Node* temp = n->left;
			free(n);
			return temp;
		}
		struct Node* temp = minValue(n->right);
		
		n->data = temp->data;
		
		n->right = deleteNode(n->right,temp->data);
	}
	return n;
}

struct Node* Insert(struct Node* node,int value){	// Insert
	if(node == NULL) return newNode(value);
	
	if(value == node->data)
		node->right = Insert(node->right,value);
	else if(value < node->data)
		node->left = Insert(node->left,value);
	else if(value > node->data)
		node->right = Insert(node->right,value);
		
	return node;
}

void preOrder(struct Node* node){			// Pre-order DLR
	if(node != NULL){
		printf("%d\n",node->data);
		preOrder(node->left);
		preOrder(node->right);
	}
}

void inOrder(struct Node* node){			// In-order  LDR
	if(node != NULL){
		inOrder(node->left);
		printf("%d\n",node->data);
		inOrder(node->right);
	}
}

void postOrder(struct Node* node){			// Post-order  LRD
	if(node != NULL){
		postOrder(node->left);
		postOrder(node->right);
		printf("%d\n",node->data);
	}
}

int main(int argc, char *argv[]) {
	struct Node* root = NULL;
	root = Insert(root,14);
	Insert(root,4);
	Insert(root,15);
	Insert(root,3);
	Insert(root,9);
	Insert(root,14);
	Insert(root,18);
	Insert(root,7);
	Insert(root,9);
	Insert(root,16);
	Insert(root,20);
	Insert(root,5);
	Insert(root,17);
	Insert(root,4);
	Insert(root,5);
	
	printf("Pre-order;\n");
	preOrder(root);	
	
	printf("In-oreder:\n");
	inOrder(root);
	
	printf("Post-order:\n");
	postOrder(root);
	
	Find(root,20);
	
	deleteNode(root,20);
	inOrder(root);
	return 0;
}
