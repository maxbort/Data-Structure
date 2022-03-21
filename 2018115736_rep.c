#include <stdio.h>
#include <stdlib.h>

typedef struct node { //���Ḯ��Ʈ�� �ʿ��� ��带 ����ü�� ����
	struct node* left; // ���� ��带 ����Ű�� ���� ������
	struct node* right; //���� ��带 ����Ű�� ���� ������
	int data; //�����͸� �����ϱ� ���� ������ �ʵ�
}node; //���� struct�� �Ź� �������� �ʱ� �ϱ� ���� ������ ����

node* head; //���� ���ʿ� ��ġ�� head. �� head�� ���� ������ ����� left�� ����Ų��.
node* tail; //���� ���ʿ� ��ġ�� tail. �� tail�� ���� ������ ����� right�� ����Ų��.

node* make(int newdata) { //��带 �����ϴ� �Լ�
	node* Node = (node*)malloc(sizeof(node)); // ���� ���� ����� ũ�⸦ node����ü�� ũ�⸸ŭ �����Ҵ�.
	Node->left = NULL; // ���Ḯ��Ʈ�� �ֱ� ���� ���� �ƹ��͵� ����Ű�� �ʰ� �Ѵ�.
	Node->right = NULL; //���� ����
	Node->data = newdata; //������ �ʵ忡 newdata����
	return Node;
}

void init() { // ���Ḯ��Ʈ�� �ڷḦ ��� �� �ʱ�ȭ�� �ϴ� �Լ�
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node)); // head�� tail�� �޸� ���� �Ҵ�
	head->data = 0;
	tail->data = 0; //�ƹ��� �����Ͱ� ������� �ʱ� ������ �������ʵ忡 NULL ����
	head->right = tail;
	head->left = head;
	tail->right = tail;
	tail->left = head; //�ʱ⿡�� �����ų �����Ͱ� �����Ƿ� head�� tail�� tail�� head�� ����Ű�� �Ѵ�.
}
void push(int newdata) { //���� �����͸� �߰��ϴ� �Լ�
	node* newnode = make(newdata); //���ο� �����Ͱ� ��� ��� ����
	node* temp;
	temp = tail;
	temp->left->right = newnode; //tail�� left�� ����Ű�� ������ ����� right�� newnode�� ����Ű�� �Ѵ�.
	newnode->left = temp->left; //newnode�� left�� tail�� left�� ����Ű�� ��带 ����Ű�� �Ѵ�.
	temp->left = newnode; //tail�� left�� newnode�� ����Ű�� �Ѵ�.
	newnode->right = temp; //newnode�� right�� tail�� ����Ű�� �ϸ� ���Ḯ��Ʈ�� �� ��带 �����ϴ� ������ ������.
}


void delete(int deletedata) { // ���Ḯ��Ʈ���� ��带 �����ϴ� �Լ�
	node* temp;
	temp = head->right;
	while (temp->right != tail->data) { //head�������� deletedata�� ������ �����͸� ������ ��带 ���������� �ݺ�
		if (temp->data == deletedata) { //deletedata�� ���� data�� ������ ��带 �߰� ��
			temp->right->left = temp->left; //temp(�ӽó��)�� right�� ����Ű�� ����� left�� temp�� left�� ����Ű�� ��带 ����Ű�� �Ѵ�.
			temp->left->right = temp->right; //temp�� left�� ����Ű�� ����� right�� temp�� right�� ����Ű�� �Ѵ�.
			free(temp); // ���� ������ų ����� �޸𸮸� ����
			return;
		}
		temp = temp->right;
	}
}


void print() {
	node* temp;
	temp = head;
	while (temp->right != tail) { //head���� ���� ������ tail�� ���� �� ���� ��� ����� data�ʵ忡 ��� ���� ����Ѵ�.
		printf("%d-->", temp->data);
		temp = temp->right;
	}
	printf("%d \n", temp->data);
}


int main() {
	init();

	int menu;
	int data;
	while (1) {
		printf("\n���ϴ� �޴��� �����Ͻÿ�\n");
		printf("1. ���Ḯ��Ʈ�� ��� �߰�\n");
		printf("2. �Է��� ���� ������ ��� ����\n");
		printf("3. ���Ḯ��Ʈ ��ü ���\n");
		printf("4. ����\n");
		printf("���� ==> ");
		scanf_s("%d", &menu);

		if (menu == 4)
			break;

		switch (menu)
		{
		case 1:
			printf("�߰��� �����͸� �Է��Ͻÿ� => ");
			scanf_s("%d", &data);
			push(data);
			break;
		case 2:
			printf("������ ������ ���� �Է��Ͻÿ� => ");
			scanf_s("%d", &data);
			delete(data);
			break;
		case 3:
			print();
			break;

		}

	}

	return 0;
}
