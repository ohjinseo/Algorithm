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
		/*
		BFS는 "현재 상태"를 나타내는 모든 변수들이 개별적으로 고려되야됨. 
		아니면 최적해가 나오지 않으며, 반례가 발생함

		ex) A라는 수의 이모티콘가 있다 가정해보면,
		B개의 클립보드보다 C개의 클립보드가 시간을 단축하는 경우가 발생할 수 있음
		*/
		
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
