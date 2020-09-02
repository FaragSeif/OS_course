#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
	int data; 
	struct Node* next; 
}; 

int size = 0; 
  
struct Node* create_Node(int data) 
{ 
    // allocating space 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; 
    newNode->next = NULL; 
    return newNode; 
} 
  
void insert_node(struct Node** current, int pos, int data) 
{ 
	if (pos < 1 || pos > size + 1) 
		printf("position %d is not valid\n", pos);
	else { 
		while (pos--) {
			if (pos == 0) { 
					struct Node* temp = create_Node(data);
					temp->next = *current; 
					*current = temp; 
			} 
			else
				current = &(*current)->next; 
			} 
			size++; 
	} 
} 

void delete_node(struct Node** current, int pos) 
{ 
	if (pos < 1 || pos > size + 1) 
		printf("position %d is not valid\n", pos);
	else { 
		while (pos--) { 
			if (pos-1 == 0) { 
				(*current)->next = (*current)->next->next;
			} 
			else
				current = &(*current)->next; 
			} 
			size--; 
	} 
} 
  
void print_list(struct Node* head) 
{ 
    while (head != NULL) { 
				printf(" %d", head->data);
        head = head->next; 
    } 
    printf("  size is: %d\n", size);
} 

int main() 
{ 
	struct Node* head = NULL;

	//filling the intial list manually
	head = create_Node(5);
  head->next = create_Node(1); 
  head->next->next = create_Node(7); 
  head->next->next->next = create_Node(3);
	size = 4;

	printf("list before insertion: \n");
	print_list(head); 

	int data = 10, pos = 3; 
	printf("list after insertion of 10 at position 3: \n"); 
	insert_node(&head, pos, data); 
	print_list(head); 

	data = 1, pos = 1; 
	printf("list after insertion of 1 at position 1:  \n");
	insert_node(&head, pos, data); 
	print_list(head); 
 
	data = 20, pos = 9; 
	printf("list after insertion of 20 at position 9:  \n");
	insert_node(&head, pos, data); 
	print_list(head); 

  pos = 3; 
	printf("list after deletion of data at position 3:  \n");
	delete_node(&head, pos); 
	print_list(head);

	return 0; 
} 

