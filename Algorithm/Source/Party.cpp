#include "myheader.h"
#include <limits.h>

vector<int> visited;
vector<int> parent;
bool bfs(vector<vector<int>> rGraph, int s, int t)
{
	vector<int> temp(rGraph.size(), 0);
	swap(visited, temp);//parent초기화
	queue <int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;//시작부분
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 0; v < rGraph.size(); v++) {
			if (visited[v] == false && rGraph[u][v] > 0) {//갈 수 있는 노드라면
				q.push(v); parent[v] = u; //v의 부모는 u이다
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
	rGraph.assign(graph.begin(), graph.end());//그래프 복사
	parent.resize(rGraph.size());
	int max_flow = 0;
	while (bfs(rGraph, s, t)) {//갱신된 그래프에 대해 반복하여 bfs를 돌린다 마지막 노드 못갈 때 까지.
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v]) {//탐색 후 부모노드로 그래프를 계속해서 타고간다 
			u = parent[v]; path_flow = min(path_flow, rGraph[u][v]);//각각 에지의 최소가중치를 찾는다.
		}
		for (v = t; v != s; v = parent[v]) {//다시 그래프를 타고간다
			u = parent[v];
			rGraph[u][v] -= path_flow; //보낸 data만큼 capacity에서 뺀다
			rGraph[v][u] += path_flow; //보낸 data만큼 받는 에지를 그린다.
		}
		max_flow += path_flow;
		vector<int> temp(rGraph.size(), 0);
		swap(parent, temp);//parent초기화
	}
	return max_flow;
}


int Algorithm::Party() {
	int end;
	int N;
	int k, D_size;

	scanf_s("%d %d %d", &N, &k, &D_size);

	vector<vector<int>> graph(N + D_size + 2, vector<int>(N + D_size + 2, 0)); //그래프 2차원 벡터 0으로 초기화
																			   //#마지막 노드는 N+D_size 이다. 마지막 음식 노드는 N+D_size - 1 이다.
	for (int i = 1; i < D_size + 1; i++) {
		int food_capacity;
		scanf_s("%d", &food_capacity);
		graph[N + i][N + D_size + 1] = food_capacity; //N+i노드에서 마지막 노드(N + D_size + 1)로 가는 용량 설정
	}

	for (int i = 1; i < N + 1; i++) {//사람노드 생성
		int foods;
		scanf_s("%d", &foods);//각사람이 만들 수 있는 음식들 수
		for (int j = 1; j < foods + 1; j++) {//어떤 음식을 만들 수 있나?
			int fNum;
			scanf_s("%d", &fNum);
			graph[i][N + fNum] = 1;//최대 1개만 가져갈 수 있다.ok
		}
	}
	//k가 있으므로 0노드에서 1~N 노드까지 capacity k만큼의 에지를 연결
	for (int i = 1; i < N + 1; i++) {
		graph[0][i] = k;
	}
	//사람노드에서 순서대로 그래프 갱신을 한다.(갱신 : 보낸 data는 삭제하고 보낸받큼 받는 에지를 생성한다.)
	int result = fordFulkerson(graph, 0, N + D_size + 1);//그래프,시작,끝을 넘긴다
	printf("%d", result);

	return 0;
}