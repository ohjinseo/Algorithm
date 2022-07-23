#include<bits/stdc++.h>
using namespace std;
#define MAXC 51
#define p pair<int, int> 

int r, c, t;
int board[MAXC][MAXC];
int copy_board[MAXC][MAXC];
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

p cleaner;

bool check_range(int y, int x) {
	if (y < r && x < c && y >= 0 && x >= 0) return true;
	return false;
}

void init() {
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			board[i][k] = copy_board[i][k];
		}
	}
}

void spread() {
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			// 현재 칸이 미세먼지라면
			if (board[i][k] > 0) {

				int s_value = board[i][k] / 5;

				int s_cnt = 0;
				for (int d = 0; d < 4; d++) {
					int ny = i + dir[0][d], nx = k + dir[1][d];

					if (check_range(ny, nx) && board[ny][nx] != -1 ) {
						s_cnt++;
						copy_board[ny][nx] += s_value;
					}
				}
				copy_board[i][k] -= s_value * s_cnt;
			}
		}
	}
}

void cycle() {
	// 위쪽 순환
	for (int i = cleaner.first - 2; i >= 0; i--) {
		copy_board[i + 1][0] = copy_board[i][0];
	}

	for (int i = 1; i < c; i++) {
		copy_board[0][i - 1] = copy_board[0][i];
	}

	for (int i = 1; i <= cleaner.first; i++) {
		copy_board[i - 1][c - 1] = copy_board[i][c - 1];
	}

	for (int i = c - 2; i >= 1; i--) {
		copy_board[cleaner.first][i + 1] = copy_board[cleaner.first][i];
	}

	copy_board[cleaner.first][1] = 0;

	// 아래쪽 순환
	for (int i = cleaner.second + 2; i < r; i++) {
		copy_board[i - 1][0] = copy_board[i][0];
	}

	for (int i = 1; i < c; i++) {
		copy_board[r - 1][i - 1] = copy_board[r - 1][i];
	}

	for (int i = r - 2; i >= cleaner.second; i--) {
		copy_board[i + 1][c - 1] = copy_board[i][c - 1];
	}

	for (int i = c - 2; i > 0; i--) {
		copy_board[cleaner.second][i + 1] = copy_board[cleaner.second][i];
	}

	copy_board[cleaner.second][1] = 0;
}

int main() {
	cin >> r >> c >> t;

	bool flag = false;
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			cin >> board[i][k];
			copy_board[i][k] = board[i][k];

			if (!flag && board[i][k] == -1) {
				cleaner.first = i;
				flag = true;
			}
			else if (flag && board[i][k] == -1) {
				cleaner.second = i;
			}
		}
	}


	while (t--) {
		spread();
		cycle();
		init();
	}

	int result = 0;
	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			if (board[i][k] != -1 && board[i][k] > 0) {
				result += board[i][k];
			}
		}
	}

	cout << result;

}