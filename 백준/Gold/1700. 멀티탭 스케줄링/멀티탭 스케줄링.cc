#include<bits/stdc++.h>
using namespace std;
#define MAXN 101
/*
그리디-페이징 최적화 

1) 이미 꽂혀있는지 확인
2) 꽂혀있다면 빈 곳에 꽂음
3) 빈 곳이 없다면 앞으로 사용되지 않거나 가장 마지막에 사용될 기기를 찾음
*/

int n, k;
int a[MAXN];
bool visited[MAXN];
vector<int> v;

int main() {
	cin >> n >> k;

	for (int i = 0; i < k; i++) cin >> a[i];

	int cnt = 0;
	for (int i = 0; i < k; i++) {

		if (visited[a[i]]) continue;

		if (v.size() == n) {
			cnt++;

			int pos_index = 0, pos_machine = v[0];
			for (int s : v) {
				int last_index = MAXN;

				for (int j = i + 1; j < k; j++) {
					if (s == a[j]) { // 미래에 꽂힐 인덱스 저장
						last_index = j;
						break;
					}
				}

				// 미래에 사용되지 않을 전자기기라면? 
				if (last_index == MAXN) {
					pos_machine = s;
					break;
				}

				// 가장 먼 미래의 전자기기 저장
				if (pos_index < last_index) {
					pos_index = last_index;
					pos_machine = s;
				}
			}

			visited[pos_machine] = false;
			v.erase(find(v.begin(), v.end(), pos_machine));
		}

		visited[a[i]] = true;
		v.push_back(a[i]);
	}

	cout << cnt;
}