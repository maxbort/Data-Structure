#include <stdio.h>
#include <stdlib.h>

typedef struct node { //연결리스트에 필요한 노드를 구조체로 정의
	struct node* left; // 앞의 노드를 가리키기 위한 포인터
	struct node* right; //뒤의 노드를 가리키기 위한 포인터
	int data; //데이터를 저장하기 위한 데이터 필드
}node; //이후 struct를 매번 선언하지 않기 하기 위해 변수명 지정

node* head; //가장 앞쪽에 위치할 head. 이 head는 가장 앞쪽의 노드의 left를 가리킨다.
node* tail; //가장 뒤쪽에 위치할 tail. 이 tail은 가장 뒤쪽의 노드의 right를 가리킨다.

node* make(int newdata) { //노드를 생성하는 함수
	node* Node = (node*)malloc(sizeof(node)); // 새로 만들 노드의 크기를 node구조체의 크기만큼 동적할당.
	Node->left = NULL; // 연결리스트에 넣기 전의 노드는 아무것도 가리키지 않게 한다.
	Node->right = NULL; //위와 동일
	Node->data = newdata; //데이터 필드에 newdata저장
	return Node;
}

void init() { // 연결리스트에 자료를 담기 전 초기화를 하는 함수
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node)); // head와 tail에 메모리 동적 할당
	head->data = 0;
	tail->data = 0; //아무런 데이터가 저장되지 않기 때문에 데이터필드에 NULL 저장
	head->right = tail;
	head->left = head;
	tail->right = tail;
	tail->left = head; //초기에는 저장시킬 데이터가 없으므로 head는 tail을 tail은 head를 가리키게 한다.
}
void push(int newdata) { //새로 데이터를 추가하는 함수
	node* newnode = make(newdata); //새로운 데이터가 담긴 노드 생성
	node* temp;
	temp = tail;
	temp->left->right = newnode; //tail의 left가 가리키는 마지막 노드의 right가 newnode를 가리키게 한다.
	newnode->left = temp->left; //newnode의 left를 tail의 left가 가리키는 노드를 가리키게 한다.
	temp->left = newnode; //tail의 left가 newnode를 가리키게 한다.
	newnode->right = temp; //newnode의 right가 tail을 가리키게 하면 연결리스트에 새 노드를 삽입하는 과정이 끝난다.
}


void delete(int deletedata) { // 연결리스트에서 노드를 삭제하는 함수
	node* temp;
	temp = head->right;
	while (temp->right != tail->data) { //head에서부터 deletedata와 동일한 데이터를 가지는 노드를 만날때까지 반복
		if (temp->data == deletedata) { //deletedata와 같은 data를 가지는 노드를 발견 시
			temp->right->left = temp->left; //temp(임시노드)의 right가 가리키는 노드의 left가 temp의 left를 가리키는 노드를 가리키게 한다.
			temp->left->right = temp->right; //temp의 left가 가리키는 노드의 right가 temp의 right를 가리키게 한다.
			free(temp); // 이후 삭제시킬 노드의 메모리를 해제
			return;
		}
		temp = temp->right;
	}
}


void print() {
	node* temp;
	temp = head;
	while (temp->right != tail) { //head에서 부터 시작해 tail을 만날 때 까지 모든 노드의 data필드에 담긴 값을 출력한다.
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
		printf("\n원하는 메뉴를 선택하시오\n");
		printf("1. 연결리스트에 노드 추가\n");
		printf("2. 입력한 값을 가지는 노드 삭제\n");
		printf("3. 연결리스트 전체 출력\n");
		printf("4. 종료\n");
		printf("선택 ==> ");
		scanf_s("%d", &menu);

		if (menu == 4)
			break;

		switch (menu)
		{
		case 1:
			printf("추가할 데이터를 입력하시오 => ");
			scanf_s("%d", &data);
			push(data);
			break;
		case 2:
			printf("삭제할 데이터 값을 입력하시오 => ");
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
