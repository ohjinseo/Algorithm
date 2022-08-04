#include<bits/stdc++.h>
using namespace std;
#define MAXN 500001

int n, m;
int parent[MAXN];

int find(int a) {
	if (parent[a] == a) {
		return a;
	}

	return parent[a] = find(parent[a]);
}

bool merge(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa == pb) return true;
	if (pa < pb) {
		parent[pb] = pa;
	}
	else {
		parent[pa] = pb;
	}
	return false;
}

void init_parent() {
	for (int i = 0; i < MAXN; i++) {
		parent[i] = i;
	}
}

int main() {
	cin >> n >> m;
	init_parent();

	int t = 0, result = 0;;
	bool f = false;
	for (int i = 0; i < m; i++) {
		t++;
		int a, b; cin >> a >> b;

		if (!f && merge(a, b)) { 
			f = true;
			result = t;
		}
	}

	cout << result;
}