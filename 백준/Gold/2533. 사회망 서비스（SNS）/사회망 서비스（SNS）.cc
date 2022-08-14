#include<bits/stdc++.h>
#define MAXN 1000001
using namespace std;

int n;
vector<int> e[MAXN];
bool visited[MAXN];
int dp[MAXN][2];

void dfs(int node) {
	visited[node] = true;

	int z = 0, o = 0;
	for (int i = 0; i < e[node].size(); i++) {
		int nnode = e[node][i];
		if (!visited[nnode]) {
			dfs(nnode);
			z += dp[nnode][1];
			o += min(dp[nnode][1], dp[nnode][0]);
		}
	}

	dp[node][0] = z;
	dp[node][1] = o + 1;
}

int main() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v; 
		cin >> u >> v;

		e[u].push_back(v);
		e[v].push_back(u);
	}

	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
}