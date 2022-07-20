#include<bits/stdc++.h>
using namespace std;

int s, clip, screen, t;
bool visited[10000][10000];
int result;

/* dfs 시간초과
void dfs(int clip, int screen, int time) {
	if (result <= time || screen > s) return;

	if (screen == s) {
		result = time;
		return;
	}

	if (clip != 0) {
		dfs(clip, screen + clip, time + 1); // (2) 클립보드 화면에 붙여넣기
	}

	dfs(screen, screen, time + 1); // (1) 복사

	dfs(clip, screen - 1, time + 1); // (3) 화면 이모티콘 삭제
}
*/

/*
반례 : 872
정답 : 22
코드 : 23
*/

void bfs() {

	queue<tuple<int, int, int>> q; 

	q.push({ 0, 1, 0 });
	visited[1][0] = true;

	while (q.size()) {
		tie(clip, screen, t) = q.front(); q.pop();

		if (screen == s) {
			result = t; break;
		}

		if (clip != 0 && !visited[screen + clip][clip]) {
			q.push({ clip, screen + clip, t + 1 });
			visited[screen + clip][clip] = true;
		}

		if (clip != screen) {
			q.push({ screen, screen, t + 1 }); 
		}

		if (screen > 2 && !visited[screen - 1][clip]) {
			q.push({ clip, screen - 1, t + 1 });
			visited[screen - 1][clip] = true;
		}
	}
}

int main() {
	cin >> s;

	bfs();

	cout << result;
}