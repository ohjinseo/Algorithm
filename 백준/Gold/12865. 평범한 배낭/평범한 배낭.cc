#include<bits/stdc++.h>
using namespace std;
#define p pair<int, int>

int n, k;
vector<p> v;
int dp[100][100001];

// 2^cnt 연산
int c(int cnt, int w) {
	if (cnt == n) return 0;
	if (dp[cnt][w]) return dp[cnt][w];

	int v1 = 0;
	if (w + v[cnt].first <= k) {
		// 물건 포함
		v1 = c(cnt + 1, w + v[cnt].first) + v[cnt].second;
	}

	// 물건 미포함
	int v2 = c(cnt + 1, w);

	return dp[cnt][w] = max(v1, v2);
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a, b });
	}

	cout << c(0, 0);
}