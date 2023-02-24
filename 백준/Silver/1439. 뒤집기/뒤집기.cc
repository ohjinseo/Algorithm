#include<iostream>
#include<iostream>

using namespace std;

int main(){
	string s;
	cin >> s;
	
	int idx = 0;
	
	int z = 0, o = 0;
	char prev = s[idx];  
	
	while(idx != s.length()){
		if(prev != s[idx]){
			if(prev == '0') z++;
			else o++;
		}
			
		prev = s[idx];
		idx++;
	}
	
	if(prev == '0') z++;
	else o++;
	
	cout << min(z, o);	
}