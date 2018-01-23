#include "myheader.h"
/*
마지막 줄에는 백준이가 승리하기 위해 건설해야 할 건물의 번호 W가 주어진다. (1 ≤ N ≤ 1000, 1 ≤ K ≤ 100000 , 1≤ X,Y,W ≤ N, 0 ≤ D ≤ 100000)
*/
int Time[1001], dp[1001];
vector<int> rv_node[1001];//노드가 가르키는 다른 노드
vector<int> ss;
bool visit[1001] = { false, };
queue<int> Q;
int rv_node_clear() {
	for (int i = 0; i < 1000; i++) {
		vector<int> temp;
		rv_node[i].swap(temp);
	}
	return 0;
}
int max(int a) {
	int M = 0;
	for (int i = 0; i < rv_node[a].size(); i++) {
		if (dp[rv_node[a][i]] > M) M = dp[rv_node[a][i]];
	}
	M += Time[a];
	return M;
}

int BFS() {
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i = 0; i < rv_node[now].size(); i++) {
			if (!visit[rv_node[now][i]]) {
				Q.push(rv_node[now][i]);
				visit[rv_node[now][i]] = true;
				BFS();
			}
		}
		ss.push_back(now);//0~순회하는 순서
	}
	return 0;
}
int Algorithm::ACM_Craft() {
	int T;
	vector<int> Res;
	scanf_s("%d", &T);//테스트케이스
	while (T--) {
		fill_n(dp, 1001, 0);
		fill_n(Time, 1001, 0);
		fill_n(visit, 1001, false);
		rv_node_clear();
		vector<int> temp;
		ss.swap(temp);

		int N, K, W;
		scanf_s("%d%d", &N, &K);
		for (int i = 1; i <= N; i++) {
			scanf_s("%d", &Time[i]);
		}
		for (int i = 1; i <= K; i++) { //가장 첫 입력이 시작 건물 이 아닐 수 있음, 1≤ X,Y,W ≤ N
			int start, end;
			scanf_s("%d%d", &start, &end);
			rv_node[end].push_back(start);
		}
		scanf_s("%d", &W);
		Q.push(W);
		BFS();
		for (int i = 0; i < ss.size(); i++) {
			dp[ss[i]] = max(ss[i]);//dp[i]는 rv_node[i]의 최대값
		}
		Res.push_back(dp[W]);
	}

	for (int i = 0; i < Res.size(); i++) {
		printf("%d\n", Res[i]);
	}
	system("pause");
	return 0;
}