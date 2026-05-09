#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* insertFirst(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}

	newNode->next = head;
	return newNode;
}

// 마지막에 노드 추가 함수
Node* insertLast(Node* head, int data) {
	// 새로운 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL; // 새 노드는 리스트의 끝을 나타냄

	// 리스트가 비어 있는 경우
	if (head == NULL) {
		return newNode; // 새 노드가 리스트의 시작점이 됨
	}

	// 리스트에 기존 노드가 있는 경우
	Node* current = head;
	while (current->next != NULL) { // 마지막 노드를 찾음
		current = current->next;
	}
	current->next = newNode; // 마지막 노드의 next에 새 노드를 연결

	return head; // 리스트의 시작점(head) 반환
}
// 특정 값을 가진 노드 뒤에 삽입
void insertAfterValue(Node* head, int targetValue, int newData) {
	Node* current = head;

	// 노드 탐색
	while (current != NULL) {
		if (current->data == targetValue) {
			// 새 노드 생성 및 삽입
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = newData;
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
		current = current->next;
	}

	// 값이 일치하는 노드가 없을 경우
	printf("값 %d를 가진 노드를 찾을 수 없습니다. 삽입하지 않습니다.\n", targetValue);
}


void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}
void freeList(Node* head) {
	Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	printf("모든 노드가 종료되었습니다\n");
}

int searchValue1(Node* head, int val) {
	if (head == NULL) {
		printf("head note가 null입니다\n");
		return -1;
	}
	Node* current = head;
	int pos = 0;
	while (current != NULL) {
		++pos;
		if (current->data == val) return pos;
		else current = current->next;
	}
	printf("값이 없습니다.\n");
	return -1;
}

void searchValue2(Node* head, int val) {
	if (head == NULL) {
		printf("Head Node가 NULL입니다\n");
		return;
	}
	if (head->data == val) {
		printf("%d의 이전값 없음.\n", val);
		printf("%d의 다음값 : %d\n", val, head->next->data);
		return;
	}
	Node* current = head;
	while (current->next != NULL && current->next->data != val) {
		current = current->next;
	}
	if (current->next == NULL) {
		printf("%d를 찾을 수 없습니다.\n", val);
		return;
	}
	printf("%d의 다음 값은 : %d\n", val, current->data);
	printf("%d의 이전 값은 : %d\n", val, current->next->next->data);
}
int main() {
	Node* head = NULL;
	int value = 0;
	for (int i = 0; i < 10; i++) {
		head = insertFirst(head, i);
	}

	printList(head);
	searchValue2(head, 5);
	value = searchValue1(head, 5);
	printf("vlaue = %d\n", value);
	freeList(head);

	return 0;
}
