#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node* prev;
	int data;
	struct Node* next;
};

	struct Node* Head = NULL;

struct Node* allocateNode(struct Node* head){		// Allocate Node
	struct Node* n = malloc(sizeof(struct Node));
	n->next = NULL;
	if(head == NULL){
		n->prev = NULL;
		return n;
		}
		
	while(1){
		if(head->next == NULL){
			n->prev = head;
			return n;
			}
		head = head->next;
	}
}

void printList(struct Node* head){			// Print List
	while(head != NULL){
		printf("Data: %d\n",head->data);
	//	printf("Next: %p\n",head->next);
		//printf("Previous: %p\n",head->prev);
		
		head = head->next;
	}
	printf("\n");
}

void printBack(struct Node* head){			// Print Back
	struct Node* last;
	printf("Printing Back\n");
	while(head != NULL){
		last = head;
		head = head->next;
	}
	while(last != NULL){
		printf("Data: %d\n",last->data);
		last = last->prev;
	}
	printf("\n");
}

int listSize(struct Node* head){			// List Size
	int size=0;
		while(head != NULL){
			size++;
			head = head->next;
		}
		return size;
}

void findElement(struct Node* head,int value){			// Find Element
	
	while(head != NULL){
		if(head->data == value){
			printf("I found the %d\n",value);
			return;
			}
		head = head->next;
	}
	printf("I can't find the value you are looking for");
}

void updateData(struct Node* head,int value,int update){			// Update Data
	
	while(head != NULL){
		
		if(head->data == value){
			head->data = update;
			return;	
		}
		head = head->next;
	}
}

void deleteNode(struct Node* head,int value){
	struct Node* temp = head;
	
	while(temp != NULL){
		if(temp->data == value){
			head->next = temp->next;
			temp->next->prev = head;
			free(temp);
			return;
		}
		head = temp;
		temp = temp->next;
	}
	printf("I didin't find the node you want to delete\n'");
	
}

void addFirst(struct Node** head,int value){			// Add First
	
	struct Node* NewNode = malloc(sizeof(struct Node));
	NewNode->data = value;
	NewNode->prev = NULL;
	NewNode->next = *head;
	(*head)->prev = NewNode;
	*head = NewNode;
	
}

void insertAfter(struct Node* head,int position,int value){			// Insert After
	
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->data = value;
	
	int size = listSize(Head);
	
	if(position<1||position>size+1)
		printf("Position is unvalid!!");
	else{
		while(position--){
			if(position == 0){
				newNode->next = head->next;
				head->next = newNode;
				newNode->prev = head;
				if(newNode->next != NULL)
					newNode->next->prev = newNode;
			}
			head = head->next;
		}
	}
}

void addEnd(struct Node* head,int value){			// Add End

	struct Node* NewNode = malloc(sizeof(struct Node));
	NewNode->data = value;
	NewNode->next = NULL;
	
	while(head->next != NULL){
		head = head->next;
	}
	NewNode->prev = head;
	head->next = NewNode;	
}

int main(int argc, char *argv[]) {			// Main
	

	struct Node* CurrentNode = NULL;
	struct Node* NewNode = NULL;
	
	CurrentNode = allocateNode(Head);
	CurrentNode->data = 1;
	Head = CurrentNode;
	
	int i;
	for(i=2;i<10;i++){
		NewNode = allocateNode(Head);
		NewNode->data = i;
		CurrentNode->next = NewNode;
		CurrentNode = NewNode;
		
	}
	
	printList(Head);
	findElement(Head,2);
	
	addEnd(Head,10);
	printList(Head);
	
	addFirst(&Head,88);
	printList(Head);
	
	insertAfter(Head,3,325);
	printList(Head);
	
	printBack(Head);
	
	updateData(Head,5,45);
	printList(Head);
	
	deleteNode(Head,4);
	printList(Head);
	
	return 0;
}
