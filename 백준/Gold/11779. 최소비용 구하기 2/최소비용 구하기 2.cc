#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define INF 100000001
#define p pair<int, int>

/*
다익스트라는 그리디적으로 탐색 후, 방문처리를함 
즉, 한번 방문한 노드는 다시 방문할 일 없으므로 1차원 배열로 기록 저장 가능

100,000 * 1,000 = 100,000,000
*/

int n, m, start, endd;
vector<p> v[MAXN];	
vector<int> h;
int dist[MAXN];
int history[MAXN];
bool visited[MAXN];

void dijkstra() {
	// 우선순위큐는 큰 값이 우선
	priority_queue<p> pq;

	pq.push({ 0, start });

	dist[start] = 0;

	while (pq.size()) {
		int cw = -pq.top().first;
		int cv = pq.top().second;

		if (cv == endd) break;

		pq.pop();

		int s = v[cv].size();
		for (int i = 0; i < s; i++) {
			int nv = v[cv][i].first;
			int nw = v[cv][i].second;

			if (!visited[nv] && dist[nv] > cw + nw) {
				dist[nv] = cw + nw;
				history[nv] = cv;

				pq.push({ -dist[nv], nv });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; 
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}

	cin >> start >> endd;

	for (int i = 0; i < MAXN; i++) dist[i] = INF;

	dijkstra();

	cout << dist[endd] << "\n";
	

	h.push_back(endd);

	while (endd != start) {
		endd = history[endd];
		h.push_back(endd);
	}

	reverse(h.begin(), h.end());

	cout << h.size() << "\n";

	for (int i : h) {
		cout << i << " ";
	}

}