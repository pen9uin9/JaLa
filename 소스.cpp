#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 102

// 구조체 선언
typedef struct {
	char arr[MAX];
	int top;
} stack;

// 스택 초기화 함수
void init_stack(stack* s) {
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(stack* s) {
	return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(stack* s) {
	return (s->top == (MAX - 1));
}

// 삽임함수
void push(stack* s, int item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		exit(1);
	}
	else s->arr[++(s->top)] = item;
}

// 삭제함수
int pop(stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->arr[(s->top)--];
}

int check_matching(char* in) {
    stack s;
    char ch, open_ch;
    int i, n = strlen(in); // n = 문자열 길이
    init_stack(&s); // 스택 초기화

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

	char arr[MAX];

	while (1) {
		fgets(arr, sizeof arr, stdin);
		if (strcmp(arr, ".\n") == 0)
			break;
		printf("%s\n", check_matching(arr) ? "yes" : "no");
	}
	return 0;
}