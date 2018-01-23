#include "myheader.h"
/*
포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
첫째 줄에 포도주 잔의 개수 n이 주어진다. (1≤n≤10,000) 둘째 줄부터 n+1번째 줄까지 포도주 잔에 들어있는 포도주의 양이 순서대로 주어진다. 포도주의 양은 1,000 이하의 음이 아닌 정수이다.
6, 10, 13, 9, 8, 1 => 6 10 9 8
*/
//dp[i] = i번째까지 가장 많이 마시는 양
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