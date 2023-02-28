#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>
#include <cmath>
#define MAXN 16
#define p pair<int, int>
using namespace std;

/*
32% 오류 -> 동시 공격을 고려해야됨 
즉, 적을 각 궁수를 순회하면서 제거하면 안됨! 
*/

int n, m, d;
vector<vector<int>> board(MAXN, vector<int>(MAXN));

vector<p> archer;
int res, answer;
int visited[MAXN];
int q_visited[MAXN][MAXN];
int dir[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
bool flag = false;


struct t {
	int y, x, time;
};

t target;


bool check_range(int y, int x) {
	if (y < n && x < m && y >= 0 && x >= 0) return true;
	return false;
}


// 가장 가까우면서 가장 왼쪽에 있는 적을 찾는다. 
void bfs(int y, int x, vector<vector<int>>& copy_board) {
	queue<t> q;
	t init;
	init.y = y, init.x = x, init.time = 0;

	q.push(init);
	memset(q_visited, false, sizeof(q_visited));
	q_visited[y][x] = true;

	flag = false;

	while (q.size()) {
		t cur_pos = q.front();
		q.pop();

		if (flag && cur_pos.time >= target.time) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cur_pos.y + dir[0][i];
			int nx = cur_pos.x + dir[1][i];
			int nt = cur_pos.time + 1;

			if (check_range(ny, nx) && !q_visited[ny][nx]) {
				q_visited[ny][nx] = true;

				t next_pos;
				next_pos.y = ny, next_pos.x = nx, next_pos.time = nt;
				q.push(next_pos);

				if ((!flag && copy_board[ny][nx] == 1) || (flag && copy_board[ny][nx] == 1 && nx < target.x)) {
					flag = true;
					target.y = ny, target.x = nx, target.time = nt;
				}

			}
		}
	}
}

void start() {
	// 격자판 깊은복사 
	vector<vector<int>> copy_board(MAXN, vector<int>(MAXN));
	copy(board.begin(), board.end(), copy_board.begin());
	

	int cnt = n;

	while (cnt--) {
		vector<p> targets; // 궁수 동시 공격을 위해 사정거리 내에 있는 적의 위치 담음 
		
		// 궁수 공격 
		for (int i = 0; i < 3; i++) {
			// 궁수에서 가장 가까운 적을 찾는다.
			bfs(archer[i].first, archer[i].second, copy_board);

			if (flag) {
				// 궁수의 사정거리 내에 적이 있다면 
				if (abs(archer[i].first - target.y) + abs(archer[i].second - target.x) <= d) {
					targets.push_back({target.y, target.x});
				}
			}
		}
		
		// 동시에 적을 제거 
		for(p pos : targets){
			if(copy_board[pos.first][pos.second] != 0){
				copy_board[pos.first][pos.second] = 0;	
				res++;
			}
		}

		// 적의 이동 
		copy_board.pop_back();
		copy_board.insert(copy_board.begin(), vector<int>(MAXN, 0));
	}
}

void comb(int idx, int cnt) {

	if (cnt == 3) {
		res = 0;

		start();

		answer = max(answer, res);

		return;
	}

	for (int i = idx; i < m; i++) {
		if (!visited[i]) {
			visited[i] = true;
			archer.push_back({ n, i });
			comb(i + 1, cnt + 1);
			archer.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m >> d;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> board[i][k];
		}
	}

	comb(0, 0);

	cout << answer;

}