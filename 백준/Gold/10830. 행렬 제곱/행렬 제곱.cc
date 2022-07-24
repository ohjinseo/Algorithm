#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define DIVN 1000
#define v vector<vector<int>>


int n;
ll b;
v matrix(5, vector<int>(5, 0));
v result(5, vector<int>(5, 0));

v mul(v m1, v m2) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			result[i][k] = 0;
			for (int z = 0; z < n; z++) {
				result[i][k] += (m1[i][z] * m2[z][k]) % DIVN;
			}
			result[i][k] %= DIVN;
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
	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> matrix[i][k];
		}
	}

	v r = dac(matrix, b);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cout << r[i][k] % DIVN << " ";
		}cout << endl;
	}
}