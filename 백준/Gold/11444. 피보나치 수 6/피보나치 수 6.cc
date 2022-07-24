#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define v vector<vector<ll>>


ll n;

v matrix(2, vector<ll>(2, 0));
v result(2, vector<ll>(2, 0));

/*
n번 째 피보나치 수열은 행렬 [[1, 1], [1, 0]]^n의 1행 2열 값이다.
*/

v mul(v m1, v m2) {
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++) {
			result[i][k] = 0;
			for (int z = 0; z < 2; z++) {
				result[i][k] += (m1[i][z] * m2[z][k]) % MOD;
			}
			result[i][k] %= MOD;
		}
	}
	return result;
}

v dac(v a, ll c) {
	if (c == 1) {
		return a;
	}

	v tmp = dac(a, c / 2);

	if (c % 2 == 0) {
		return mul(tmp, tmp);
	}
	else {
		return mul(mul(tmp, tmp), a);
	}
}

int main() {
	cin >> n;
	matrix = { {1, 1}, {1, 0} };

	v r = dac(matrix, n);

	cout << r[0][1] % MOD;
}