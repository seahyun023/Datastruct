#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define SIZE 30

typedef struct {
	int data[SIZE];
	int front;
	int rear;
}LinearQueue;

//초기화 함수
void initQueue(LinearQueue* q) {
	q->front = 0;
	q->rear = -1;
}

bool isEmpty(LinearQueue* q) {
	return q->rear < q->front; //front가 rear보다 크면 비어있음.
}

bool isFull(LinearQueue* q) {
	return q->rear == SIZE - 1; //배열 인덱스 4
}

bool enqueue(LinearQueue* q, int value) {
	if (isFull(q)) {
		printf("큐가 가득 찼습니다.\n");
		return true;
	}
	q->rear++;
	q->data[q->rear] = value;
	return true;
}

int dequeue(LinearQueue* q) {
	if (isEmpty(q)) {
		printf("큐가 비어 있습니다. \n");
		return '\0';
	}
	int value = q->data[q->front];
	q->front++;

	if (q->front > q->rear) {
		q->front = 0;
		q->rear = -1;
	}
	return value;
}

void printQueue(LinearQueue* q) {
	if (isEmpty(q)) {
		printf("큐가 비어 있습니다.\n");
		return;
	}

	for (int i = q->front; i <= q->rear; i++) {
		printf("%d ", q->data[i]);
	}
	printf("\n");
}

int main() {
	LinearQueue q;
	initQueue(&q);
	int peck;

	while (1) {
		printf("1.삽입\n2.삭제\n3.현재 큐\n4.종료\n");
		scanf("%d", &peck);

		switch (peck) {
		case 1:
			int value;
			printf("데이터 값을 입력하시오 : ");
			scanf("%d", &value);
			enqueue(&q, value);
			break;
		case 2:
			int value1 = dequeue(&q);
			if (value1 != '\0')
				printf("삭제된 값: %d\n", value1);
			break;
		case 3:
			printf("현재 큐를 출력합니다 :");
			printQueue(&q);
			break;
		case 4:
			printf("종료합니다.");
			return '\0';
			break;
		}
	}
	return 0;
}