#include <stdio.h>
int get_integer(void);
int is_prime(int n);
int main(void){
	int n;
	n = get_integer();
	if (is_prime(n) == 1)
		printf("%d은소수입니다.\n", n);
	else
		printf("%d은소수가아닙니다.\n", n);
	return 0;
}

int get_integer(void) {
	int n = 0; 
	printf("정수를입력하시오: "); 
	scanf_s("%d", &n); 
	return n; 
}
int is_prime(int n) { 
	int i; 
	for (i = 2; i < n; i++) { 
		if (n % i == 0)
		return 0; 
	}
	return 1; 
}