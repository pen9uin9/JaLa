#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}Deque;
// �ʱ�ȭ
void init_deque(Deque* q) {
	q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(Deque* q) {
	return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(Deque* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// ����ť ��� �Լ�
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
// ���� �Լ�
void add_rear(Deque* q, element item) {
	if (is_full(q)) {
		printf("ť�� ��ȭ�����Դϴ�");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
void add_front(Deque* q, element item) {
	if (is_full(q)) {
		printf("ť�� ��ȭ�����Դϴ�");
		exit(1);
	}
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
// ���� �Լ�
element delete_front(Deque* q) {
	if (is_empty(q)) {
		printf("ť�� ��������Դϴ�");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
element delete_rear(Deque* q) {
	if (is_empty(q)) {
		printf("ť�� ��������Դϴ�");
		exit(1);
	}
	int item = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return item;
}
// ���� �Լ�
element get_front(Deque* q) {
	if (is_empty(q)) {
		printf("ť�� ��������Դϴ�");
		exit(1);
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
element get_rear(Deque* q) {
	if (is_empty(q)) {
		printf("ť�� ��������Դϴ�");
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