#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

/*
	조합으로 가능한 각 세션을 구하고, dfs로 이어지는지 확인
	그리고 인구수 구함 
*/

int n;
int answer = 987654321;
int population[11];
vector<int> v[11];
char section[11];
int populationA, populationB;

int bfs(int start, char target){
	int cnt = 1;
	queue<int> q;
	bool visited[11];
	memset(visited, false, sizeof(visited));
	
	q.push(start);	
	visited[start] = true;
	
	while(q.size()){
		int cnode = q.front(); q.pop();
		
		for(int i = 0; i < v[cnode].size(); i++){
			int nnode = v[cnode][i];
			if(!visited[nnode] && section[nnode] == target){
				cnt++;
				visited[nnode] = true;
				q.push(nnode);
				
				if(target == 'A') populationA += population[nnode];
				else populationB += population[nnode];
			}
		}
	}
	
	return cnt;
}

void comb(int limit, int cnt, int idx){
	if(limit == cnt){
		
		int sectionA, sectionB;
		
		for(int i = 1; i <= n; i++){
			if(section[i] != 'A'){
				section[i] = 'B';
				sectionB = i;
			}else{
				sectionA = i;	
			}
		}
		
		populationA = population[sectionA], populationB = population[sectionB];
		
		int sum = bfs(sectionA, 'A') + bfs(sectionB, 'B');
		
		if(sum == n){
			answer = min(answer, abs(populationA - populationB));		
		}
		
		return;	
	}
	
	for(int i = idx; i <= n; i++){
		section[i] = 'A';
		comb(limit, cnt + 1, i + 1);
		section[i] = 'B';
	}
}

int main(){
	cin >> n;
		
	for(int i = 1; i <= n; i++){
		cin >> population[i];	
	}
	
	for(int i = 1; i <= n; i++){
		int t; cin >> t;
		while(t--){
			int u; cin >> u;
			v[i].push_back(u);		
		}
	}
	
	for(int i = 1; i < n; i++){
		comb(i, 0, 1);	
	}

	if(answer == 987654321) cout << "-1";
	else cout << answer;
}



