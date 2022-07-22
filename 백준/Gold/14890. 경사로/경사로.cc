#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

int n, l;
int board[MAXN][MAXN];
bool visited[MAXN][MAXN];

bool check_range(int y, int x) {
	if (y < n && x < n && y >= 0 && x >= 0) return true;
	return false;
}

bool check(int y, int x, int val, bool row, bool forward) {
	// 행검사
	if (row) {
		if (forward) {
			for (int i = x; i < x + l; i++) {
				if (!check_range(y, i) || board[y][i] != val) {
					return false;
				}
				visited[y][i] = true;
			}
			return true;
		}
		else {
			for (int i = x - l + 1; i <= x; i++) {
				if (!check_range(y, i) || visited[y][i] || board[y][i] != val) {
					return false;
				}
				visited[y][i] = true;
			}
			return true;
		}
	}
	// 열검사
	else {
		if (forward) {
			for (int i = y; i < y + l; i++) {
				if (!check_range(i, x) || board[i][x] != val) {
					return false;
				}
				visited[i][x] = true;
			}
			return true;
		}
		else {
			for (int i = y - l + 1; i <= y; i++) {
				if (!check_range(i, x) || visited[i][x] || board[i][x] != val) {
					return false;
				}
				visited[i][x] = true;
			}
			return true;
		}
	}
}


int main() {
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> board[i][k];
		}
	}

	int result = 0;

	// 행 탐색
	for (int i = 0; i < n; i++) {
		for (int k = 0; k <= n; k++) {

			if (k == n - 1 || k == n) { 
				result++;
				break;
			}

			int t = board[i][k] - board[i][k + 1];

			if (t == 0) continue;

			if (abs(t) != 1) break;


			if (abs(t) == 1) {
				// 현재가 크다면
				if (t > 0) {
					if (check(i, k + 1, board[i][k + 1], true, true)) {
						k += l - 1;
					}
					else {
						break;
					}
				}
				// 현재가 작다면
				else {
					if (check(i, k, board[i][k], true, false)) {
						continue;
					}
					else {
						break;
					}
				}
			}
		}
	}

	memset(visited, false, sizeof(visited));

	// 열검사
	for (int i = 0; i < n; i++) {
		for (int k = 0; k <= n; k++) {
			if (k == n - 1 || k == n) {
				result++;
				break;
			}

			int t = board[k][i] - board[k + 1][i];

			if (t == 0) continue;

			if (abs(t) != 1) break;

			if (abs(t) == 1) {
				// 현재가 크다면
				if (t > 0) {
					if (check(k + 1, i, board[k + 1][i], false, true)) {
						k += l - 1;
					}
					else {
						break;
					}
				}
				// 현재가 작다면
				else {
					if (check(k, i, board[k][i], false, false)) {
						continue;
					}
					else {
						break;
					}
				}
			}
		}
	}

	cout << result;
}