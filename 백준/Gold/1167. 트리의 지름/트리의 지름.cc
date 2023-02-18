#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAXV 100001
#define p pair<int, int>
using namespace std;

/*
1. 임의 노드에서 가장 먼 노드 a를 찾는다. 
2. a에서 가장 긴 노드까지의 길이를 구한다. 
*/

int v, farNode;
vector<p> tree[MAXV]; 
bool visited[MAXV];
int maxDist;

void find_leaf(int cnode, int total){
	if(maxDist < total){
		maxDist = total;
		farNode = cnode;
	}
	
	for(int i = 0; i < tree[cnode].size(); i++){
		int nnode = tree[cnode][i].first;
		int ndist = tree[cnode][i].second;
		
		if(!visited[nnode]){
			visited[nnode] = true;
			find_leaf(nnode, total + ndist);
		}
	}
}

int main(){
	cin >> v;
	for(int i = 0; i < v; i++){
		int cv; cin >> cv;
		
		while(true){
			int nv, dist;
			cin >> nv;
			
			if(nv == -1) break;
			
			cin >> dist;
			
			tree[cv].push_back({nv, dist});
		}
	}
	
	visited[1] = true;
	find_leaf(1, 0);
	
	memset(visited, false, sizeof(visited));
	
	visited[farNode] = true;
	find_leaf(farNode, 0);
	
	cout << maxDist;
}