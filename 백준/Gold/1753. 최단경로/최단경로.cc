#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

int V, E, K;
vector<pair<int, int>> graph[20001];
int dist[20001];

void dijkstra(int start) {
	// 노드까지의 거리, 해당 노드
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(dist[start], start));


	while (!pq.empty()) {
		int weight = -1 * pq.top().first;
		int node = pq.top().second;

		pq.pop();

		for (int i = 0; i < graph[node].size(); i++) {

			int nnode = graph[node][i].first;
			int nweight = graph[node][i].second;


			if (dist[node] + nweight < dist[nnode]) {
				dist[nnode] = dist[node] + nweight;

				pq.push(make_pair(-1 * dist[nnode], nnode));

				//우선순위큐 기본으로 큰 값이 가장 앞에옴
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back(make_pair(b, c));
	}

	for (int i = 0; i < 20001; i++) {
		dist[i] = INT_MAX;
	}

	dist[K] = 0;
	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (dist[i] != INT_MAX)
			cout << dist[i] << "\n";
		else
			cout << "INF" << "\n";
	}
}