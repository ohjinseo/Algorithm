#include<bits/stdc++.h>
using namespace std;

bool visited[9];
int n, m;
int asd[9];

void dfs(int cnt, int k) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++) cout << asd[i] << " ";
		cout << "\n";
		return;
	}
	else {
		for (int i = k; i <= n; i++) {
				asd[cnt] = i;
				dfs(cnt + 1, i);
			
		}
	}
}

int main() {
	cin >> n >> m;

	dfs(0, 1);
}