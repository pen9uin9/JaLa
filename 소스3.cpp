#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}Deque;
// 초기화
void init_deque(Deque* q) {
	q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(Deque* q) {
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(Deque* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 원형큐 출력 함수
void deque_print(Deque* q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d |", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
// 삽입 함수
void add_rear(Deque* q, element item) {
	if (is_full(q)) {
		printf("큐가 포화상태입니다");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
void add_front(Deque* q, element item) {
	if (is_full(q)) {
		printf("큐가 포화상태입니다");
		exit(1);
	}
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
// 삭제 함수
element delete_front(Deque* q) {
	if (is_empty(q)) {
		printf("큐가 공백상태입니다");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element delete_rear(Deque* q) {
	if (is_empty(q)) {
		printf("큐가 공백상태입니다");
		exit(1);
	}
	int item = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return item;
}
// 열람 함수
element get_front(Deque* q) {
	if (is_empty(q)) {
		printf("큐가 공백상태입니다");
		exit(1);
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
element get_rear(Deque* q) {
	if (is_empty(q)) {
		printf("큐가 공백상태입니다");
		exit(1);
	}
	return q->data[q->rear];
}
int main(void) {
	Deque queue;
	init_deque(&queue);
	for (int i = 0; i < 3; i++){
		add_front(&queue, i);
		deque_print(&queue);
	}
	for (int i = 0; i < 3; i++){
		delete_rear(&queue);
		deque_print(&queue);
	}
	return 0;
}