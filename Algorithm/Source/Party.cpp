#include "myheader.h"
#include <limits.h>

vector<int> visited;
vector<int> parent;
bool bfs(vector<vector<int>> rGraph, int s, int t)
{
	vector<int> temp(rGraph.size(), 0);
	swap(visited, temp);//parent�ʱ�ȭ
	queue <int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;//���ۺκ�
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 0; v < rGraph.size(); v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {//�� �� �ִ� �����
				q.push(v); parent[v] = u; //v�� �θ�� u�̴�
				visited[v] = true;
			}
		}
	}
	return (visited[t] == true);
}

int fordFulkerson(vector<vector<int>> graph, int s, int t)
{
	int u, v;
	vector<vector<int>> rGraph;
	rGraph.assign(graph.begin(), graph.end());//�׷��� ����
	parent.resize(rGraph.size());
	int max_flow = 0;
	while (bfs(rGraph, s, t)) {//���ŵ� �׷����� ���� �ݺ��Ͽ� bfs�� ������ ������ ��� ���� �� ����.
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {//Ž�� �� �θ���� �׷����� ����ؼ� Ÿ���� 
			u = parent[v]; path_flow = min(path_flow, rGraph[u][v]);//���� ������ �ּҰ���ġ�� ã�´�.
		}
		for (v = t; v != s; v = parent[v]) {//�ٽ� �׷����� Ÿ����
			u = parent[v];
			rGraph[u][v] -= path_flow; //���� data��ŭ capacity���� ����
			rGraph[v][u] += path_flow; //���� data��ŭ �޴� ������ �׸���.
		}
		max_flow += path_flow;
		vector<int> temp(rGraph.size(), 0);
		swap(parent, temp);//parent�ʱ�ȭ
	}
	return max_flow;
}


int Algorithm::Party() {
	int end;
	int N;
	int k, D_size;

	scanf_s("%d %d %d", &N, &k, &D_size);

	vector<vector<int>> graph(N + D_size + 2, vector<int>(N + D_size + 2, 0)); //�׷��� 2���� ���� 0���� �ʱ�ȭ
																			   //#������ ���� N+D_size �̴�. ������ ���� ���� N+D_size - 1 �̴�.
	for (int i = 1; i < D_size + 1; i++) {
		int food_capacity;
		scanf_s("%d", &food_capacity);
		graph[N + i][N + D_size + 1] = food_capacity; //N+i��忡�� ������ ���(N + D_size + 1)�� ���� �뷮 ����
	}

	for (int i = 1; i < N + 1; i++) {//������ ����
		int foods;
		scanf_s("%d", &foods);//������� ���� �� �ִ� ���ĵ� ��
		for (int j = 1; j < foods + 1; j++) {//� ������ ���� �� �ֳ�?
			int fNum;
			scanf_s("%d", &fNum);
			graph[i][N + fNum] = 1;//�ִ� 1���� ������ �� �ִ�.ok
		}
	}
	//k�� �����Ƿ� 0��忡�� 1~N ������ capacity k��ŭ�� ������ ����
	for (int i = 1; i < N + 1; i++) {
		graph[0][i] = k;
	}
	//�����忡�� ������� �׷��� ������ �Ѵ�.(���� : ���� data�� �����ϰ� ������ŭ �޴� ������ �����Ѵ�.)
	int result = fordFulkerson(graph, 0, N + D_size + 1);//�׷���,����,���� �ѱ��
	printf("%d", result);

	return 0;
}