#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

/*
1. 2 1 2
2. 2 0 2
3. 2 1
4. 1 1
5. 1

** O(k)로 구현시 시간초과남
v.erase 시간초과남
*/

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second < b.second) return true;
    return false;
}

int solution(vector<int> food_times, long long k) {
    int answer = -1;
    vector<pair<int, int>> v;
    
    for(int i = 0; i < food_times.size(); i++){
        v.push_back({food_times[i], i + 1});
    }
    
    sort(v.begin(), v.end()); // 오름차순 정렬

    
    int prev = 0;
    int size = v.size();
    
    // food_times 원소에 접근
    for(int i = 0; i < size; i++){
        ll current_width = size - i;
        ll current_height = v[i].first - prev;
        
        prev = v[i].first;
        
        // 만약 앞 요소와 높이가 같은 경우 무시 (이미 계산)
        if(current_height == 0) {
            continue;
        }
        
        if(current_width * current_height <= k){
            k -= (current_width * current_height);
        }
        else{
            int idx = k % current_width + i;
            
            // 다시 원상 복귀
            sort(v.begin() + i, v.end(), cmp);

            answer = v[idx].second;
            break;
        }
    }
    
    return answer;
}