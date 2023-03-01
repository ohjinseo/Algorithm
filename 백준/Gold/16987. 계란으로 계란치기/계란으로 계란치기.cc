#include <iostream>
#include <algorithm>
using namespace std;

int n;
int s[301];
int w[301];
int answer;

int cal_break(){
	int cnt = 0;
	
	for(int i = 0; i < n; i++){
		if(s[i] <= 0) cnt++;
	}
	
	return cnt;
}

void per(int cur_egg){ // 손에 든 계란 

	if(cur_egg == n){
		answer = max(answer, cal_break());
		return;
	}
	
	if(s[cur_egg] <= 0) {
		per(cur_egg + 1);
		return;
	}
	
	bool broken = false;
	
	for(int i = 0; i < n; i++){
		if(cur_egg == i || s[i] <= 0) continue;
		broken = true;
		// 계란치기!!!!!!
		s[i] -= w[cur_egg];
		s[cur_egg] -= w[i];

		per(cur_egg + 1);
				 
		s[i] += w[cur_egg];
		s[cur_egg] += w[i];
	}
	
	if(!broken) per(cur_egg + 1);
}


int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> s[i] >> w[i];	
	}
	
	per(0);
	
	cout << answer;
}