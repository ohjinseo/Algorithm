#include<bits/stdc++.h>
using namespace std;
#define MAXN 801
#define p pair<int, int>
#define INF 160000001

int n, e;
vector<p> v[MAXN];
int dist[MAXN];



void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<p> pq;

	pq.push({ 0, start });

	while (pq.size()) {
		int cw = -pq.top().first;
		int cn = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cn].size(); i++) {
			int nn = v[cn][i].first;
			int nw = v[cn][i].second;

			if (dist[nn] > cw + nw) {
				dist[nn] = cw + nw;
				pq.push({ -dist[nn], nn });
			}
		}
	}
}

int main() {
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	fill_n(dist, MAXN, INF);

	dijkstra(v1);

	int v1toS = dist[1], v1tov2 = dist[v2], v1toE = dist[n];

	fill_n(dist, MAXN, INF);

	dijkstra(v2);

	int v2toS = dist[1], v2toE = dist[n];

	int result1 = 0, result2 = 0;
	if (v1toS == INF || v1tov2 == INF || v2toE == INF) result1 = INF;
	else result1 = v1toS + v1tov2 + v2toE;

	if (v2toS == INF || v1tov2 == INF || v1toE == INF) result2 = INF;
	else result2 = v2toS + v1tov2 + v1toE;

	if (result1 == INF && result2 == INF) cout << "-1";
	else {
		int result = result1 < result2 ? result1 : result2;
		cout << result;
	}

}
