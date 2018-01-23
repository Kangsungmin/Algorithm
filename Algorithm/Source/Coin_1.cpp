#include "myheader.h"
/*
n���� ������ ������ �ִ�. ������ ������ ��Ÿ���� ��ġ�� �ٸ���.
�� �������� ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. �� ����� ���� ���Ͻÿ�.
(������ ������ �� ���� ����� �� �ִ�.)
ù°�ٿ� n, k�� �־�����. (1 �� n �� 100, 1 �� k �� 10,000) ���� n���� �ٿ��� ������ ������ ��ġ�� �־�����.
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
