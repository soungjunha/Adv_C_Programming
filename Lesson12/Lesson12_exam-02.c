#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int price;
	struct node* next;
}NODE;

void free_list(NODE* head) {
	NODE* current = head;
	NODE* nextNode = NULL;

	while (current != NULL) {
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
}

void print_node(NODE* head) {
	NODE* tmp = head;
	while (tmp != NULL)
	{
		printf("%d, ", tmp->price);
		tmp = tmp->next;
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

NODE* delete_node(NODE* head, int target) {
	NODE* tmp = head;
	NODE* prev = NULL;
	if (tmp != NULL && tmp->price == target) {
		head = tmp->next;
		free(tmp);
		return head;
	}

	while (tmp != NULL && tmp->price != target)
	{
		prev = tmp;
		tmp = tmp->next;
	}

	if (tmp == NULL) {
		printf("해당 노드가 없습니다.\n");
		return head;
	}
	prev->next = tmp->next;
	free(tmp);
	return head;
}

int main() {
	NODE* head = NULL;
	int data;
	do
	{
		scanf("%d", &data);
		if (data > 0)
			head = add_node(head, data);
		else if (data < 0)
			head = delete_node(head, -data);
	} while (data != 0);
	print_node(head);
	free_list(head);
}
