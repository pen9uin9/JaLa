#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 102

// ����ü ����
typedef struct {
	char arr[MAX];
	int top;
} stack;

// ���� �ʱ�ȭ �Լ�
void init_stack(stack* s) {
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(stack* s) {
	return (s->top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full(stack* s) {
	return (s->top == (MAX - 1));
}

// �����Լ�
void push(stack* s, int item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		exit(1);
	}
	else s->arr[++(s->top)] = item;
}

// �����Լ�
int pop(stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->arr[(s->top)--];
}

int check_matching(char* in) {
    stack s;
    char ch, open_ch;
    int i, n = strlen(in); // n = ���ڿ� ����
    init_stack(&s); // ���� �ʱ�ȭ

    for (i = 0; i < n; i++) {
        ch = in[i];
        switch (ch) {
            // �� ��ȣ
        case '(': case '[':
            push(&s, ch);
            break;

            // �� ��ȣ
        case ')': case ']':
            if (is_empty(&s)) {
                return 0;
            }
            else {
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']')) {
                    return 0;
                }
                break;
            }
        }
    }
    // ��ȣ ¦ �� ������ ���� ��ȯ
    if (!is_empty(&s)) {
        return 0;
    }
    return 1;
}

int main(void) {

	char arr[MAX];

	while (1) {
		fgets(arr, sizeof arr, stdin);
		if (strcmp(arr, ".\n") == 0)
			break;
		printf("%s\n", check_matching(arr) ? "yes" : "no");
	}
	return 0;
}