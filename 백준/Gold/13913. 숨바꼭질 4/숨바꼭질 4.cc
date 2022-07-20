#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;

int n, k;
pair<int, int> d[3] = { {1, -1}, {1, 1}, {2, 0} };
bool visited[MAXN];
int pre[MAXN];

int range(int n) {
	if (n >= 0 && n < MAXN) return true;
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	queue<int> q;
	q.push(n);

	visited[n] = true;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (cur == k) break;

		for (int i = 0; i < 3; i++) {
			int next = (d[i].first * cur) + d[i].second;

			if (range(next) && !visited[next]) {
				visited[next] = true;
				pre[next] = cur;
				q.push(next);
			}
		}
	}
	vector<int> v;

	int here = k;
	while (1) {
		v.push_back(here);

		if (here == n) break;
		here = pre[here];
	}

	reverse(v.begin(), v.end());

	cout << v.size() - 1 << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}