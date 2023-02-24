#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 32001

using namespace std;

int n, m;
vector<int> v[MAXN];
vector<int> answer;
int degree[MAXN];
bool visited[MAXN];

int main(){
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int from, to; cin >> from >> to;
		
		v[to].push_back(from);
		degree[from]++;
	}
	
	queue<int> q;
	
	for(int i = 1; i <= n; i++){
		if(degree[i] == 0){
			q.push(i);
			answer.push_back(i);
			visited[i] = true;
		}
	}
	
	while(q.size()){
		int cnode = q.front();
		q.pop();
		
		for(int i = 0; i < v[cnode].size(); i++){
			int nnode = v[cnode][i];
			degree[nnode]--;
			
			if(!visited[nnode] && degree[nnode] == 0){
				visited[nnode] = true;
				q.push(nnode);
				answer.push_back(nnode);
			}
		}
	}
	
	reverse(answer.begin(), answer.end());
	for(int i : answer) cout << i << " ";
}