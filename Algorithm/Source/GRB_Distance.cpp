#include "myheader.h"
#define Red 0
#define Green 1
#define Blue 2
int min(int a, int b) {
	return (a < b) ? a : b;
}
int Algorithm::GRB_Distance() {
	int N, RGB[1001][3], dp[1001][3], ptr = 1;//dp[i][c] i집을 c로 칠할때 i집까지의 최소값
	scanf_s("%d", &N);

	while (N--) {
		scanf_s("%d %d %d", &RGB[ptr][Red], &RGB[ptr][Green], &RGB[ptr][Blue]);
		if (ptr == 1) {
			dp[ptr][Red] = RGB[ptr][Red];
			dp[ptr][Green] = RGB[ptr][Green];
			dp[ptr][Blue] = RGB[ptr][Blue];
		}
		else {
			dp[ptr][Red] = RGB[ptr][Red] + min(dp[ptr - 1][Green], dp[ptr - 1][Blue]);
			dp[ptr][Green] = RGB[ptr][Green] + min(dp[ptr - 1][Red], dp[ptr - 1][Blue]);
			dp[ptr][Blue] = RGB[ptr][Blue] + min(dp[ptr - 1][Red], dp[ptr - 1][Green]);
		}
		ptr++;
	}
	int res = min(dp[ptr - 1][Red], dp[ptr - 1][Green]);
	res = min(res, dp[ptr - 1][Blue]);
	printf("%d", res);
	system("pause");
	return 0;
}