#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ����ü ����
typedef struct {
    char* stack;
    char capacity;
    int top;
} stack;

// ���� �ʱ�ȭ �Լ�
void init_stack(stack* s, int capacity) {
    s->stack = (char*)malloc(s->capacity * sizeof(char));
    s->top = -1;
    s->capacity = capacity;
    if (s->stack == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(EXIT_FAILURE);
    }
}

// ���� ���� ���� �Լ�
int is_empty(stack* s) {
    return (s->top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full(stack* s) {
    return (s->top == (s->capacity - 1));
}

// �����Լ�
void push(stack* s, char item) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->stack = (char*)realloc(s->stack, s->capacity * sizeof(char));
        if (s->stack == NULL) {
            fprintf(stderr, "�޸� ���Ҵ� ����\n");
            exit(EXIT_FAILURE);
        }
    }
    s->stack[++(s->top)] = item;
}

// �����Լ�
char pop(stack * s) {
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[(s->top)--];
}

void free_stack(stack* s) {
    free(s->stack);
}

int check_matching(char* in) {
    stack s;
    char ch, open_ch;
    int i, n = strlen(in); // n = ���ڿ� ����
    init_stack(&s, n); // ���� �ʱ�ȭ

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

    stack s;

    while (1) {
        fgets(s->stack, sizeof char, stdin);
        if (strcmp(s->stack, ".\n") == 0)
            break;
        printf("%s\n", check_matching(s) ? "yes" : "no");
    }
    return 0;
}