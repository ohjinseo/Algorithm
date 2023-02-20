#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main(){
	cin >> n;	
	int x, y;
	
	cin >> x >> y;
	int left = x, right = y, sum = 0;
	n--;
	while(n--){
		
		cin >> x >> y;
		
		if(x <= right){ // 현재 선분이 포함된다면 
			right = max(right, y);
		}
		else{
			sum += (right - left);
			left = x;
			right = y;
		}
	}
	
	sum += (right - left);
	
	cout << sum;
}