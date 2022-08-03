#include<bits/stdc++.h>
using namespace std;
#define p pair<int, int>
#define MAXN 1000001

int n;
bool visited[MAXN];
int history[MAXN];
vector<int> v;

int main() {
	cin >> n;

	queue<p> q;
	q.push({ 1, 0 });
	visited[1] = true;
	int result = 0;

	while (q.size()) {
		int c = q.front().first;
		int t = q.front().second; q.pop();

		if (c == n) {
			result = t;
			break;
		}

		if (c * 3 < MAXN && !visited[c * 3] ) {
			q.push({ c * 3, t + 1 });
			visited[c * 3] = true;
			history[c * 3] = c;
		}

		if (c * 2 < MAXN && !visited[c * 2]) {
			q.push({ c * 2, t + 1 });
			visited[c * 2] = true;
			history[c * 2] = c;
		}

		if (c + 1 < MAXN && !visited[c + 1]) {
			q.push({ c + 1, t + 1 });
			visited[c + 1] = true;
			history[c + 1] = c;
		}
	}

	int a = 1;


	cout << result << "\n";

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}

	cout << n << " ";
	while (n != 1) {
		cout << history[n] << " ";
		n = history[n];
	}
}