#include "myheader.h"
/*
계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나,
다음 다음 계단으로 오를 수 있다.
연속된 세 개의 계단을 모두 밟아서는 안된다. 단, 시작점은 계단에 포함되지 않는다.
마지막 도착 계단은 반드시 밟아야 한다.
입력의 첫째 줄에 계단의 개수가 주어진다.

둘째 줄부터 한 줄에 하나씩 제일 아래에 놓인 계단부터 순서대로 각 계단에 쓰여 있는 점수가 주어진다.
계단의 개수는 300이하의 자연수이고, 계단에 쓰여 있는 점수는 10,000이하의 자연수이다.
*/
int max(int a, int b) {
	return (a > b) ? a : b;
}
int Algorithm::Stair_1() {
	int end;
	int N, ptr = 1;
	int dp[302], st[302];
	scanf_s("%d", &N);

	while (N--) {
		int v;
		scanf_s("%d", &v);
		st[ptr] = v;
		if (ptr == 1) dp[ptr] = v;
		else if (ptr == 2) dp[ptr] = st[1] + v;
		else if (ptr == 3) max(st[1], st[2]) + v;
		else dp[ptr] = max(dp[ptr - 2], st[ptr - 1] + dp[ptr - 3]) + v;
		ptr++;
	}
	printf("%d", dp[ptr - 1]);
	scanf_s("%d", &end);
	return 0;
}