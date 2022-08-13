#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001

int t, n, m;
int a[MAXN], b[MAXN], result;
vector<int> asum, bsum;

int main() {
	cin >> t >> n >> m;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	asum.push_back(sum);

	sum = 0;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		sum += b[i];
	}
	bsum.push_back(sum);

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int k = i; k < n + i - 1; k++) {
			sum += a[k % n];
			asum.push_back(sum);
		}
	}
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int k = i; k < m + i - 1; k++) {
			sum += b[k % m];
			bsum.push_back(sum);
		}
	}
	asum.push_back(0);
	bsum.push_back(0);

	sort(asum.begin(), asum.end());
	sort(bsum.begin(), bsum.end());

	int left = 0, right = bsum.size() - 1;

	while (left < asum.size() && right >= 0) {
		int s = asum[left] + bsum[right];

		if (s == t) {
			int ar = asum[left], br = bsum[right];
			int ac = 0, bc = 0;
			while (left < asum.size() && asum[left] == ar) {
				ac++; left++;
			}

			while (right >= 0 && bsum[right] == br) {
				bc++; right--;
			}
			// cout << ar << " " << br << " " << ac << " " << bc << endl;
			result += ac * bc;
		}

		if (s < t) {
			left++;
		}
		if(s > t) {
			right--;
		}
	}

	cout << result;
}