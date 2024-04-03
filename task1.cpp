#include <stdio.h>

int main() {
	int N, X;

	scanf_s("%d %d", &N, &X);

	int arr[10000];
	for (int i = 0; i < N; i++) {
		scanf_s("%d", arr + N);
		if (X > *(arr + N)) {
			printf("%d ", *(arr + N));
		}
	}
}