#include<iostream>
#include<algorithm>

using namespace std;

string croatian[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

string str;

int main() {

	cin >> str;

	for (int i = 0; i < 8; i++) {
		while (1) {
			int idx = str.find(croatian[i]);
			if (idx == string::npos) break;
			str.replace(idx, croatian[i].length(), "a");
		}
	}

	cout << str.length();
}