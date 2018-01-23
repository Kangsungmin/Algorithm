#include "myheader.h"
int count_0 = 0, count_1 = 0;
int fibonacci(int n) {
	if (n == 0) {
		count_0++;
		return 0;
	}
	else if (n == 1) {
		count_1++;
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int res[41][2];
int  r_ptr = 0;
int Algorithm::Fibonacci_Dp(){
	int end;
	int N;

	scanf_s("%d", &N);

	while (N--) {
		int num;
		scanf_s("%d", &num);
		fibonacci(num);
		res[r_ptr][0] = count_0;
		res[r_ptr++][1] = count_1;
		count_0 = 0; count_1 = 0;
	}

	for (int i = 0; i < r_ptr; i++) {
		printf("%d %d\n", res[i][0], res[i][1]);
	}

	scanf_s("%d", &end);
	return 0;
}