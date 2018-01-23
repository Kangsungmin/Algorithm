#include "myheader.h"
/*
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다.
이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그 경우의 수를 구하시오.
(각각의 동전은 몇 개라도 사용할 수 있다.)
첫째줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다.
*/

int coin[102];
int dp[10001];
int Algorithm::Coin_1() {
	int N, K;
	fill_n(dp, 10001, 0);
	dp[0] = 1;
	scanf_s("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf_s("%d", &coin[i]);
	}
	for (int i = 1; i <= N; i++) {
		for (int p = 0; p <= K; p++) {//1~10
			if (p + coin[i] < 10001)
				dp[p + coin[i]] += dp[p];
		}
	}
	for (int i = 1; i <= K; i++) {
		printf("%d ,", dp[i]);
	}

	system("pause");
	return 0;
}
