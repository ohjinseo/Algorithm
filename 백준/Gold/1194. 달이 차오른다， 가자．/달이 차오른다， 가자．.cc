#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
#define t tuple<int, int, int>

int n, m, result = INT_MAX, dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1}};
char maze[MAXN][MAXN];
bool keys[26];

bool check_range(int y, int x) {
	if (y < n && x < m && y >= 0 && x >= 0) return true;
	return false;
}

void bfs(t start) {
	int y, x, time;
	tie(y, x, time) = start;
	bool visited[MAXN][MAXN] = {false, };
	queue<t> q;
	q.push(start);
	visited[y][x] = true;

	while (q.size()) {
		int cy, cx, ctime;
		tie(cy, cx, ctime) = q.front(); q.pop();

		if (result != INT_MAX && ctime > result) break;

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[0][i], nx = cx + dir[1][i];

			if (check_range(ny, nx) && !visited[ny][nx]) {

				// 다음 위치가 목적지라면
				if (maze[ny][nx] == '1' && ctime + 1 < result) {
					result = ctime + 1;
					return;
				}

				// 다음 위치가 빈 공간이라면
				else if (maze[ny][nx] == '.' || maze[ny][nx] == '0') {
					q.push({ ny, nx, ctime + 1 });
				}

				// 다음 위치가 키라면
				else if (maze[ny][nx] >= 'a' && maze[ny][nx] <= 'z') {


					// 키를 이미 가지고 있다면
					if (keys[maze[ny][nx] - 'a']) {
						q.push({ ny, nx, ctime + 1 });
					}
					// 키가 없다면
					else {
						keys[maze[ny][nx] - 'a'] = true;
						bfs({ ny, nx, ctime + 1 });
						keys[maze[ny][nx] - 'a'] = false;
					}
				}

				// 다음 위치가 문이라면
				else if (maze[ny][nx] >= 'A' && maze[ny][nx] <= 'Z') {
					// 키를 가지고 있다면
					if (keys[maze[ny][nx] - 'A']) {
						q.push({ ny, nx, ctime + 1 });
					}
					// 키가 없다면
					else {
						continue;
					}
				}

				visited[ny][nx] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	t start;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> maze[i][k];
			if (maze[i][k] == '0') {
				start = make_tuple(i, k, 0);
			}
		}
	}

	bfs(start);

	if (result != INT_MAX) {
		cout << result;
	}
	else {
		cout << "-1";
	}
}