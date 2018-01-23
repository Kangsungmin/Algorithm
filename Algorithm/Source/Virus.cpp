#include "myheader.h"
/*
ù° �ٿ��� ��ǻ���� ���� �־�����. ��ǻ���� ���� 100 �����̰� �� ��ǻ�Ϳ��� 1�� ���� ���ʴ�� ��ȣ�� �Ű�����.
��° �ٿ��� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ�� ���� ���� �־�����. �̾ �� ����ŭ �� �ٿ� �� �־�
��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ���� ��ȣ ���� �־�����.
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
		G[s].push_back(e);//G[s]���� s�� ����� ������ ��ȣ�� ���´�.
		G[e].push_back(s);
	}
	Q.push(1);
	visit[1] = 1;
	while (!Q.empty()) {
		int now = Q.front();//���� ���
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