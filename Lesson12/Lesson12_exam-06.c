#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	int price;
	char* product;
	struct node* right;
	struct node* down;
}NODE;

void free_list(NODE* head) {
	NODE* current = head;
	NODE* nextNode = NULL;

	while (current != NULL) {
		nextNode = current->right;
		free(current->product);
		free(current);
		current = nextNode;
	}
}

void print_node(NODE* head) {
	NODE* tmp = head;
	printf("가격순 정렬: ");

	while (tmp != NULL)
	{
		printf("(%s, %d),", tmp->product, tmp->price);
		tmp = tmp->right;
	}
	printf("\n이름순 정렬: ");
	tmp = head;
	while (tmp->down != NULL) tmp = tmp->right;
	while (tmp != NULL)
	{
		printf("(%s, %d),", tmp->product, tmp->price);
		tmp = tmp->right;
	}
	printf("\n");
}

NODE* create_node(int data, char* name) {
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->product = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(new->product, name);
	new->price = data;
	new->right = NULL;
	new->down = NULL;
	return new;
}

NODE* add_head(NODE* head, int data, char* name) {
	NODE* new = create_node(data, name);
	if (head == NULL) { head = new; }
	else
	{
		NODE* tmp = head;
		while (tmp->down != NULL) tmp = tmp->down;
		tmp->down = new;
	}
	return head;
}

NODE* add_node(NODE* head, int data, char* name) {

	if (head != NULL) {
		NODE* new = create_node(data, name);
		NODE* tmp = head;
		while (tmp->right != NULL) tmp = tmp->right;
		tmp->right = new;

		NODE* new1 = create_node(data, name);
		tmp = head->down;
		while (tmp->right != NULL) tmp = tmp->right;
		tmp->right = new1;

	}
	else
	{
		head = add_head(head, data, name);
		head = add_head(head, data, name);
	}

	return head;
}
/*
NODE* delete_node(NODE* head, int target) {
	NODE* tmp = head;
	NODE* prev = NULL;
	if (tmp != NULL && tmp->price == target) {
		head = tmp->right;
		free(tmp);
		return head;
	}

	while (tmp != NULL && tmp->price != target)
	{
		prev = tmp;
		tmp = tmp->right;
	}

	if (tmp == NULL) {
		printf("해당 노드가 없습니다.\n");
		return head;
	}
	prev->right = tmp->right;
	free(tmp);
	return head;
}*/

NODE* swap(NODE* head, NODE* node1, NODE* node2) {
	if (node1 == node2) return head;

	NODE* prev1 = NULL, * prev2 = NULL, * temp = head;

	while (temp != NULL && (prev1 == NULL || prev2 == NULL)) {
		if (temp->right == node1) prev1 = temp;
		if (temp->right == node2) prev2 = temp;
		temp = temp->right;
	}

	if (head == node1) head = node2;
	else if (head == node2) head = node1;

	if (prev1) prev1->right = node2;
	if (prev2) prev2->right = node1;

	temp = node1->right;
	node1->right = node2->right;
	node2->right = temp;

	return head;
}

NODE* sort(NODE* head) {
	if (head == NULL) return head;

	int swapped;
	NODE* ptr1;
	NODE* lptr = NULL;

	do {
		swapped = 0;
		ptr1 = head;

		while (ptr1->right != lptr) {
			if (ptr1->price > ptr1->right->price) {
				head = swap(head, ptr1, ptr1->right);
				swapped = 1;
			}
			else {
				ptr1 = ptr1->right;
			}
		}
		lptr = ptr1;
	} while (swapped);

	return head;
}

NODE* sort_name(NODE* head) {
	if (head == NULL) return head;

	int swapped;
	NODE* ptr1;
	NODE* lptr = NULL;

	do {
		swapped = 0;
		ptr1 = head;

		while (ptr1->right != lptr) {
			if (strcmp(ptr1->product, ptr1->right->product) > 0) {
				head = swap(head, ptr1, ptr1->right);
				swapped = 1;
			}
			else {
				ptr1 = ptr1->right;
			}
		}
		lptr = ptr1;
	} while (swapped);

	return head;
}

int main() {
	NODE* head = NULL;
	FILE* drink = fopen("drink.txt", "r");
	int price = 0;
	char name[100];
	while (fscanf(drink, "%s %d", name, &price) == 2) {
		head = add_node(head, price, name);
	}
	head = sort(head);
	head->down = sort_name(head->down);

	print_node(head);

	free_list(head->down);
	free_list(head);
}
