#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int l, c;
vector<char> gathers; // 모음
vector<char> consonants; // 자음 
vector<string> answer;
string gat = "aeiou";

void consonant_permutation(int limit, int cnt, int idx, string res){
	if(limit == cnt){
		sort(res.begin(), res.end());
		answer.push_back(res);
		return;	
	}
	
	for(int i = idx; i < consonants.size(); i++){
		consonant_permutation(limit, cnt + 1, i + 1, res + consonants[i]);	
	}
}

void gather_permutation(int limit, int cnt, int idx, string res){
	if(limit == cnt){
		// 이때 자음의 수는 l - limit
		int consonant_num = l - limit;
		consonant_permutation(consonant_num, 0, 0, res);
		return;	
	}
	
	for(int i = idx; i < gathers.size(); i++){
		gather_permutation(limit, cnt + 1, i + 1, res + gathers[i]);
	}
}
 
int main(){
	cin >> l >> c;
	
	for(int i = 0; i < c; i++){
		char a; cin >> a;
		
		if(gat.find(a) != string::npos){
			gathers.push_back(a);	
		}
		else{
			consonants.push_back(a);
		}
	}
	
	sort(gathers.begin(), gathers.end());
	sort(consonants.begin(), consonants.end());
	
	// 자음의 갯수 
	for(int i = 1; i <= l-2; i++){
		gather_permutation(i, 0, 0, "");
	}
	
	sort(answer.begin(), answer.end());
	
	for(string s : answer) cout << s << "\n";
}