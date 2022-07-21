#include<bits/stdc++.h>
using namespace std;
#define MAXN 1501
#define p pair<int, int>

/*
L1(백조1), L2(백조2)

처음 생각한거

L1, L2 외곽선 물을 bfs로 큐에 넣고 1초씩 깎음 (깎은 좌표는 pop하면서 방문처리 -> X를 1 or 2로 변환) -> 두 개의 큐 (w1_q, w2_q)
외곽선을 트리(분리집합)에도 삽입 

깎인 좌표들은 큐에 넣고 기존 좌표 pop
깎인 좌표들을 큐에 넣을 때 트리에도 넣어서 부모노드가 백조 좌표인지 확인

만약 같다면 L1과 L2는 만날 수 있음!

--------- 실패

백조가 있는 곳도 물이었음

물에 대한 큐, 물 다음 큐
백조에 대한 큐, 백조 다음 큐 

총 4개가 필요함 

외곽선을 담기 위해 큐를 2개 사용!!!
*/

int r, c;
char lake[MAXN][MAXN];
bool visited[MAXN][MAXN];

p swan;
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };

queue<p> water_Q, water_NQ, swan_Q, swan_NQ;

bool check_range(int y, int x) {
	if (y < r && x < c && y >= 0 && x >= 0) return true;
	return false;
}

void water_cut() {
	while (water_Q.size()) {
		int cy = water_Q.front().first, cx = water_Q.front().second;
		water_Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[0][i], nx = cx + dir[1][i];

			if (check_range(ny, nx) && lake[ny][nx] == 'X') {
				lake[ny][nx] = '.';
				water_NQ.push({ ny, nx });
			}
		}
	}
}

bool swan1_bfs() {
	while (swan_Q.size()) {
		int cy = swan_Q.front().first, cx = swan_Q.front().second;
		swan_Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[0][i], nx = cx + dir[1][i];

			if (check_range(ny, nx) && !visited[ny][nx]) {
				if (lake[ny][nx] == '.') {
					visited[ny][nx] = true;
					swan_Q.push({ ny, nx });
				}
				// 다음 백조가 탐색할 큐
				else if (lake[ny][nx] == 'X') {
					visited[ny][nx] = true;
					swan_NQ.push({ ny, nx });
				}

				else {
					return true;
				}
			}
		}
	}
	return false;
}




int main() {
	cin >> r >> c;

	bool flag = false;

	for (int i = 0; i < r; i++) {
		string s; cin >> s;

		for (int k = 0; k < c; k++) {
			lake[i][k] = s[k];

			if (lake[i][k] != 'X') water_Q.push({ i, k });

			if (lake[i][k] == 'L' && !flag) {
				swan = { i, k };
			}
		}
	}

	// 1. 백조 탐색
	// 2. 물을 깎음

	swan_Q.push(swan);
	visited[swan.first][swan.second] = true;

	int d = 0;

	while (true) {
		d++;

		water_cut();
		water_Q = water_NQ;

		while (water_NQ.size()) water_NQ.pop();

		if (swan1_bfs()) break;
		swan_Q = swan_NQ;

		while (swan_NQ.size()) swan_NQ.pop();
	}

	cout << d;
}