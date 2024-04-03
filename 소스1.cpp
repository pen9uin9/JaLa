#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 구조체 선언
typedef struct {
    char* stack;
    char capacity;
    int top;
} stack;

// 스택 초기화 함수
void init_stack(stack* s, int capacity) {
    s->stack = (char*)malloc(s->capacity * sizeof(char));
    s->top = -1;
    s->capacity = capacity;
    if (s->stack == NULL) {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(EXIT_FAILURE);
    }
}

// 공백 상태 검출 함수
int is_empty(stack* s) {
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(stack* s) {
    return (s->top == (s->capacity - 1));
}

// 삽임함수
void push(stack* s, char item) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->stack = (char*)realloc(s->stack, s->capacity * sizeof(char));
        if (s->stack == NULL) {
            fprintf(stderr, "메모리 재할당 오류\n");
            exit(EXIT_FAILURE);
        }
    }
    s->stack[++(s->top)] = item;
}

// 삭제함수
char pop(stack * s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
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
    int i, n = strlen(in); // n = 문자열 길이
    init_stack(&s, n); // 스택 초기화

    for (i = 0; i < n; i++) {
        ch = in[i];
        switch (ch) {
            // 앞 괄호
        case '(': case '[':
            push(&s, ch);
            break;

            // 뒷 괄호
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
    // 괄호 짝 안 맞으면 에러 반환
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