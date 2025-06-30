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
		nextNode = current->right; // 다음 노드를 저장
		free(current);            // 현재 노드 메모리 해제
		current = nextNode;       // 다음 노드로 이동
	}
}

void print_node(NODE* head) {
	NODE* tmp = head;
	int f = 0;
	if (tmp->price % 2 == 1)
	{
		printf("홀수: ");
		f = 1;
	}
	else
	{
		printf("짝수: ");
		f = 2;
	}

	while (tmp != NULL)
	{
		printf("%d, ", tmp->price);
		tmp = tmp->right;
	}
	tmp = head->down;
	if (f == 1) printf("\n짝수: ");
	else if (f == 2) printf("\n홀수: ");
	while (tmp != NULL)
	{
		printf("%d, ", tmp->price);
		tmp = tmp->right;
	}
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
		printf("해당 노드가 없습니다.\n");
		return head;
	}
	prev->right = tmp->right;
	free(tmp);
	return head;
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
	free_list(head->down);
	free_list(head);
}
