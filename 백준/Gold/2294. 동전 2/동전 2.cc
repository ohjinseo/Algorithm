#include<bits/stdc++.h>
using namespace std;
#define MAXK 100001

int n, k;
int m[101],dp[MAXK];

int main() {
	cin >> n >> k;
	
	fill_n(dp, MAXK, MAXK);

	for (int i = 0; i < n; i++) {
		cin >> m[i];
		dp[m[i]] = 1; 
	}

	sort(m, m + n);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j <= k; j++) {
			if (j - m[i] >= 0) {
				dp[j] = min(dp[j], dp[j - m[i]] + 1);
			}
		}
	}

	if (dp[k] != MAXK) cout << dp[k];
	else cout << "-1";
}