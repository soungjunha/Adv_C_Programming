#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int price;
	struct node* next;
}NODE;

void print_node(NODE* head) {
	NODE* tmp = head;
	while (tmp != NULL)
	{
		printf("%d, ", tmp->price);
		tmp = tmp->next;
	}
}

void free_list(NODE* head) {
	NODE* current = head;
	NODE* nextNode = NULL;

	while (current != NULL) {
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
}

NODE* create_node(int data) {
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->data = data;
	new->next = NULL;
	return new;
}

NODE* add_node(NODE* head, int data) {
	NODE* new = create_node(data);
	if (head == NULL) { head = new; }
	else
	{
		NODE* tmp = head;
		while (tmp->next != NULL) tmp = tmp->next;
		tmp->next = new;
	}
	return head;
}

int main() {
	NODE* head = NULL;
	int data = -1;
	while (data != 0)
	{
		scanf("%d", &data);
		head = add_node(head, data);
	}
	print_node(head);
}
