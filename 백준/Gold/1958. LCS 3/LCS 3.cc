#include<bits/stdc++.h>
using namespace std;
#define MAXN 101

string a, b, c;
int dp[MAXN][MAXN][MAXN];

int main() {
	cin >> a >> b >> c;
	int as = a.size(), bs = b.size(), cs = c.size();

	for (int i = 1; i <= as; i++) {
		for (int k = 1; k <= bs; k++) {
			for (int j = 1; j <= cs; j++) {
				if (a[i - 1] == b[k - 1] && b[k - 1] == c[j - 1]) {
					dp[i][k][j] = dp[i - 1][k - 1][j - 1] + 1;
				}
				else {
					dp[i][k][j] = max(dp[i - 1][k][j], max(dp[i][k - 1][j], dp[i][k][j - 1]));
				}
			}
		}
	}

	cout << dp[a.size()][b.size()][c.size()];

}