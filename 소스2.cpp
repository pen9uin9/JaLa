#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* arr;
    int top;
    int capacity;
} stack;

void init_stack(stack* s, int capacity) {
    s->top = -1;
    s->capacity = capacity;
    s->arr = (char*)malloc(capacity * sizeof(char));
    if (s->arr == NULL) {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(EXIT_FAILURE);
    }
}

int is_empty(stack* s) {
    return (s->top == -1);
}

int is_full(stack* s) {
    return (s->top == (s->capacity - 1));
}

void push(stack* s, char item) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->arr = (char*)realloc(s->arr, s->capacity * sizeof(char));
        if (s->arr == NULL) {
            fprintf(stderr, "메모리 재할당 오류\n");
            exit(EXIT_FAILURE);
        }
    }
    s->arr[++(s->top)] = item;
}

char pop(stack* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(EXIT_FAILURE);
    }
    return s->arr[(s->top)--];
}

void free_stack(stack* s) {
    free(s->arr);
}

int check_matching(char* in) {
    stack s;
    char ch, open_ch;
    int i, n = strlen(in);
    init_stack(&s, n);

    for (i = 0; i < n; i++) {
        ch = in[i];
        switch (ch) {
        case '(':
        case '[':
            push(&s, ch);
            break;

        case ')':
        case ']':
            if (is_empty(&s)) {
                free_stack(&s);
                return 0;
            }
            else {
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']')) {
                    free_stack(&s);
                    return 0;
                }
                break;
            }
        }
    }

    if (!is_empty(&s)) {
        free_stack(&s);
        return 0;
    }

    free_stack(&s);
    return 1;
}

int main(void) {
    char arr[1000]; // 배열 크기 변경
    size_t input_length;

    while (1) {
        //printf("Enter a string: ");
        if (fgets(arr, sizeof(arr), stdin) == NULL) // fgets() 함수 사용
            break;
        input_length = strlen(arr);
        if (input_length == 2 && arr[0] == '.' && arr[1] == '\n')
            break;
        printf("%s\n", check_matching(arr) ? "yes" : "no");
    }

    return 0;
}
