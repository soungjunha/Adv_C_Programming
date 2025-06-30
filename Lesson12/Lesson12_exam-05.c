#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int price;
	struct node* right;
	struct node* down;
}NODE;

void free_list(NODE* head) {
	NODE* current = head;
	NODE* nextNode = NULL;

	while (current != NULL) {
		nextNode = current->right;
		free(current);
		current = nextNode;
	}
}

void print_node(NODE* head) {
	NODE* tmp = head;
	int f = 0;
	if (tmp->price % 2 == 1)
	{
		printf("È¦¼ö: ");
		f = 1;
	}
	else
	{
		printf("Â¦¼ö: ");
		f = 2;
	}

	while (tmp != NULL)
	{
		printf("%d, ", tmp->price);
		tmp = tmp->right;
	}
	tmp = head->down;
	if (f == 1) printf("\nÂ¦¼ö: ");
	else if (f == 2) printf("\nÈ¦¼ö: ");
	while (tmp != NULL)
	{
		printf("%d, ", tmp->price);
		tmp = tmp->right;
	}
	printf("\n");
}

NODE* create_node(int data) {
	NODE* new = (NODE*)malloc(sizeof(NODE));
	new->data = data;
	new->right = NULL;
	new->down = NULL;
	return new;
}

NODE* add_head(NODE* head, int data) {
	NODE* new = create_node(data);
	if (head == NULL) { head = new; }
	else
	{
		NODE* tmp = head;
		while (tmp->down != NULL) tmp = tmp->down;
		tmp->down = new;
		new->down = tmp;
	}
	return head;
}

NODE* add_node(NODE* head, int data) {
	NODE* new = create_node(data);
	if ((head != NULL && head->down != NULL) || (head != NULL && head->price % 2 == data % 2)) {
		if (data % 2 == head->price % 2) {
			NODE* tmp = head;
			while (tmp->right != NULL) tmp = tmp->right;
			tmp->right = new;
		}
		else {
			NODE* tmp = head->down;
			while (tmp->right != NULL) tmp = tmp->right;
			tmp->right = new;
		}
	}
	else { head = add_head(head, data); }

	return head;
}

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
		printf("ÇØ´ç ³ëµå°¡ ¾ø½À´Ï´Ù.\n");
		return head;
	}
	prev->right = tmp->right;
	free(tmp);
	return head;
}

void sort(NODE* head) {
	int tmp;
	NODE* ptr1;
	NODE* lptr = NULL;

	if (head == NULL)
		return;

	do {
		tmp = 0;
		ptr1 = head;

		while (ptr1->right != lptr) {
			if (ptr1->price > ptr1->right->price) {
				int temp = ptr1->price;
				ptr1->price = ptr1->right->price;
				ptr1->right->price = temp;
				tmp = 1;
			}
			ptr1 = ptr1->right;
		}
		lptr = ptr1;
	} while (tmp);
}

int main() {
	NODE* head = NULL;
	int data = 0;
	do
	{
		scanf("%d", &data);
		if (data > 0)
			head = add_node(head, data);
		else if (data < 0)
			head = delete_node(head, -data);
	} while (data != 0);
	print_node(head);

	sort(head);
	sort(head->down);

	print_node(head);

	free_list(head->down);
	free_list(head);
}
