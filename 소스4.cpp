#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 101
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s);
int is_empty(StackType* s);
int is_full(StackType* s);
void push(StackType* s, element item);
element pop(StackType* s);
int check_matching(const char* in);

int main(void) {
	while (1) {
		char arr[101];
		fgets(arr, 101, stdin);

		if (arr[0] == '.') break;

		if (check_matching(arr) == 1)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		//fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		//fprintf(stderr, "���� ���� ����\n");
	}
	else return s->data[(s->top)--];
}

int check_matching(const char* in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);  			// n= ���ڿ��� ����


	for (i = 0; i < n; i++) {
		ch = in[i];			// ch = ���� ����
		switch (ch) {
		case '(':   case '[':    case '{':
			push(&s, ch);
			break;

		case ')':   case ']':    case '}':
			if (is_empty(&s))  return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}')) {
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0; // ���ÿ� ���������� ����
	return 1;
}
