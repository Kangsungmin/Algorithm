#include "myheader.h"
/*
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다.
둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩
네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.
*/
vector<int> G[101];
int visit[101];
queue<int> Q;
int Algorithm::Virus() {
	int N, K, count = 0;
	scanf_s("%d %d", &N, &K);
	fill_n(visit, 101, 0);
	while (K--) {
		int s, e;
		scanf_s("%d %d", &s, &e);
		G[s].push_back(e);//G[s]에는 s와 연결된 노드들의 번호가 나온다.
		G[e].push_back(s);
	}
	Q.push(1);
	visit[1] = 1;
	while (!Q.empty()) {
		int now = Q.front();//현재 노드
		Q.pop();
		for (int j = 0; j < G[now].size(); j++) {
			int linkedNode = G[now][j];
			if (visit[linkedNode] == 0) {
				Q.push(linkedNode);
				visit[linkedNode] = 1;
				count++;
			}
		}
	}
	printf("%d", count);
	system("pause");
	return 0;
}