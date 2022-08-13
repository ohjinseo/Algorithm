#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

string str1, str2;
int dp[1001][1001];
stack<char> s;

int main() {
	cin >> str1 >> str2;

	for (int i = 0; i <= str1.length(); i++) {
		for (int k = 0; k <= str2.length(); k++) {
			if (i == 0 || k == 0) {
				dp[i][k] = 0;
				continue;
			}

			if (str1[i - 1] == str2[k - 1]) {
				dp[i][k] = dp[i - 1][k - 1] + 1;
			}
			else {
				dp[i][k] = max(dp[i - 1][k], dp[i][k - 1]);
			}
		}
	}

	cout << dp[str1.length()][str2.length()] << endl;
	
	if (dp[str1.length()][str2.length()] != 0) {


	int i = str1.length();
	int k = str2.length();
	while (1) {
		if (dp[i][k] == 0) break;

		if (dp[i][k] == dp[i][k - 1]) {
			k--;
		}
		else if (dp[i][k] == dp[i - 1][k]) {
			i--;
		}
		else {
			s.push(str1[i - 1]);
			i--;
			k--;
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	}
}