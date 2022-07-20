#include<bits/stdc++.h>
using namespace std;
#define MAXN 300001
#define p pair<int, int>
#define ll long long

int n, k;
vector<p> li;
vector<int> bags;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		li.push_back({a, b});
	}

	sort(li.begin(), li.end());

	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		bags.push_back(a);
	}

	sort(bags.begin(), bags.end());

	ll result = 0;
	int i = 0;
	priority_queue<int> pq;

	for (int bag : bags) {

		while (i < n && li[i].first <= bag) {
			pq.push(li[i++].second);
		}
		
		if (!pq.empty()) {
			result += pq.top(); pq.pop();
		}
	}

	cout << result;
}

