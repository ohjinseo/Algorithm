#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v vector<vector<ll>>


int n, m, p;

v matrix(100, vector<ll>(100, 0));
v result(100, vector<ll>(100, 0));

v mul(v m1, v m2) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			result[i][k] = 0;
			for (int z = 0; z < n; z++) {
				result[i][k] += (m1[i][z] * m2[z][k]) % m;
			}
			result[i][k] %= m;
		}
	}
	return result;
}

v dac(v a, int c) {
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
	while (true) {

	cin >> n >> m >> p;

	if (n == 0 && m == 0 && p == 0) break;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> matrix[i][k];
		}
	}

	v r = dac(matrix, p);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cout << r[i][k] % m << " ";
		}cout << "\n";
	}cout << "\n";
	}
}