#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left,*right;
	int height;
};

struct Node* newNode(int value){				// New Node
	struct Node* NewNode = malloc(sizeof(struct Node));
	NewNode->data = value;
	NewNode->left = NewNode->right = NULL;
	NewNode->height = 1;
	return NewNode;
}

int Max(int a,int b){				// Max
	if(a>b)
		return a;
	else
		return b;
}

int Height(struct Node* n){			// Height
	if(n == NULL)
		return 0;
	return n->height;
}

int getBalance(struct Node* n){			// Balance
	if(n == NULL)
		return 0;
	return Height(n->left) - Height(n->right);
}

struct Node* rightRotate(struct Node* n){				// Right Rotate
	struct Node* l = n->left;
	struct Node* r = l->right;
	
	l->right = n;
	n->left = r;
	
	n->height = Max(Height(n->left),Height(n->right))+1;
	l->height = Max(Height(l->left),Height(l->right))+1;
	
	return l;
	
}

struct Node* leftRotate(struct Node* n){			// Rotate Left
	struct Node* l = n->right;
	struct Node* r = l->left;
	
	l->left = n;
	n->right = r;
	
	n->height = Max(Height(n->left),Height(n->right))+1;
	l->height = Max(Height(l->left),Height(l->right))+1;
	
	return l;
}






struct Node* Insert(struct Node* node,int value){	// Insert
	if(node == NULL) return newNode(value);
	
	if(value == node->data)
		return node;
	else if(value < node->data)
		node->left = Insert(node->left,value);
	else if(value > node->data)
		node->right = Insert(node->right,value);
		
	node->height = 1 + Max(Height(node->left),Height(node->right));
	
	int balance = getBalance(node);
	
	if(balance > 1 && value < node->left->data)
		return rightRotate(node);
		
	if(balance < -1 && value > node->right->data)
		return leftRotate(node);
		
	if(balance > 1 && value > node->left->data){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	} 
	if(balance < -1 && value < node->right->data){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
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
	

	return 0;
}
