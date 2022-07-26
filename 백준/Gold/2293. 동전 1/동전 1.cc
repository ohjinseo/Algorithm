#include<bits/stdc++.h>
using namespace std;

int n, k;
int dp[10001];
int m[101];

/*
i/j  1 2 3 4 5 6 7 8 9 10
1    1 1 1 1 1 1 1 1 1 1
2    1 2 2 3 3 4 4 5 5 6
5    1 2 2 3 4 5 6 7 8 10

if(j-m[i] >= 0){
	// dp[i - 1][j] : 이전 숫자 이하의 수로 J를 구성하는 경우의 수
	// dp[i][j-m[i]] : i숫자로 J를 구성하는 경우의 수

	dp[i][j] = dp[i - 1][j] + dp[i][j-m[i]];
}
else{
	dp[i][j] = 이전 숫자 이하의 수로 J를 구성하는 경우의 수
}

2차원 배열 시 메모리초과 뜸
칼럼부분은 덮어쓸 수 있으므로 일차원 배열로 표현 가능

*/

int main() {
	cin >> n >> k;

	m[0] = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		m[i] = a;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= m[i]) {
				dp[j] += dp[j - m[i]];
			}
		}
	}
	cout << dp[k];
}