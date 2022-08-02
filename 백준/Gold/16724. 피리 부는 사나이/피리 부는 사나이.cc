#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001
#define p pair<int, int>

int n, m, result;
char mapp[MAXN][MAXN];
p parent[MAXN][MAXN];
map<char, p> dir;

p find(int y, int x) {
	int py = parent[y][x].first, px = parent[y][x].second;

	if (py == y && px == x) {
		p tmp;
		tmp.first = y; tmp.second = x;
		return tmp;
	}
	else {
		return parent[y][x] = find(py, px);
	}
}

bool check_range(int y, int x) {
	if (y > 0 && x > 0 && y <= n && x <= m) return true;
	return false;
}

void dfs(int y, int x) {
	if (!check_range(y, x)) {
		parent[y][x] = { y, x };
		result++;
		return;
	}

	int ny = y + dir[mapp[y][x]].first, nx = x + dir[mapp[y][x]].second;
	
	if (parent[ny][nx].first == 0 && parent[ny][nx].second == 0) {
		parent[ny][nx] = { y, x };
		dfs(ny, nx);
	}
	else if (find(y, x) == find(ny, nx)) {
		result++;
		return; 
	}
	else if (find(y, x) != find(ny, nx)) {
		return;
	}
}

int main() {
	cin >> n >> m;

	dir.insert({ 'R', {0, 1} });
	dir.insert({ 'L', {0, -1} });
	dir.insert({ 'U', {-1, 0} });
	dir.insert({ 'D', {1, 0} });

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			cin >> mapp[i][k];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			if (parent[i][k].first == 0 && parent[i][k].second == 0) {
				parent[i][k] = { i, k };
				dfs(i, k);
			}
		}
	}

	cout << result;
}
