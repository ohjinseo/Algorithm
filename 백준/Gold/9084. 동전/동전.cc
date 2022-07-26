#include<bits/stdc++.h>
using namespace std;

int T, money[21];

int main() {
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			money[i] = a;
		}

		cin >> m;

		int dp[10001] = { 0, };

		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= m; k++) {
				if (money[i] <= k) {
					dp[k] += dp[k - money[i]];
				}
			}
		}

		cout << dp[m] << "\n";
	}
}