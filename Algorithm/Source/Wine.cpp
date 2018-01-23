#include "myheader.h"
/*
������ ���� �����ϸ� �� �ܿ� ����ִ� �����ִ� ��� ���ž� �ϰ�, ���� �Ŀ��� ���� ��ġ�� �ٽ� ���ƾ� �Ѵ�.
�������� ���� �ִ� 3���� ��� ���� ���� ����.
ù° �ٿ� ������ ���� ���� n�� �־�����. (1��n��10,000) ��° �ٺ��� n+1��° �ٱ��� ������ �ܿ� ����ִ� �������� ���� ������� �־�����. �������� ���� 1,000 ������ ���� �ƴ� �����̴�.
6, 10, 13, 9, 8, 1 => 6 10 9 8
*/
//dp[i] = i��°���� ���� ���� ���ô� ��
//dp[1] = w[1]
//dp[i] = max(dp[i - 3] + w[i - 1], dp[i - 2])
int w[10002], dp[10002];
int max(int a, int b) {
	return (a > b) ? a : b;
}
int Algorithm::Wine() {
	int N, ptr = 1, res = 0;
	scanf_s("%d", &N);

	while (N--) {
		scanf_s("%d", &w[ptr]);
		if (ptr == 1) dp[ptr] = w[ptr];
		else if (ptr == 2) dp[ptr] = w[2] + w[1];
		else if (ptr == 3) dp[3] = w[3] + max(w[1], w[2]);
		else
			dp[ptr] = max(dp[ptr - 3] + w[ptr - 1], dp[ptr - 2]) + w[ptr];
		if (dp[ptr - 1] > dp[ptr]) dp[ptr] = dp[ptr - 1];
		ptr++;
	}

	printf("%d", dp[ptr - 1]);
	system("pause");
	return 0;
}