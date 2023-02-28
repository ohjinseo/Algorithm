#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#define p pair<vector<vector<int>>, int>

using namespace std;

vector<vector<int>> board(3, vector<int>(3));
unordered_map<string, int> visited;
int dir[2][4] = {{-1, 1, 0, 0}, {0, 0, -1, 1}};
int answer = -1;

bool check_range(int y, int x){
	if(y < 3 && x < 3 && y >= 0 && x >= 0) return true;
	return false;	
}

bool check_clean(vector<vector<int>>& tmp){
	int cnt = 1;
	
	for(int i = 0; i < 3; i++){
		for(int k = 0; k < 3; k++){
			if(i == 2 && k == 2) return true;
			if(tmp[i][k] != cnt++) return false;
		}
	}
	
	return true;
}

string boardToString(vector<vector<int>>& tmp){
	string s;
	for(int i = 0; i < 3; i++){
		for(int k = 0; k < 3; k++){
			s += to_string(tmp[i][k]);	
		}
	}
	
	return s;
}

int main(){
	for(int i = 0; i < 3; i++){
		for(int k = 0; k < 3; k++){
			cin >> board[i][k];
		}
	}
	
	queue<p> q;
	q.push({board, 0}); // deep copy가 일어남 
	
	while(q.size()){
		// 현재 상태의 board 
		vector<vector<int>> cur_board = q.front().first;
		int cnt_move = q.front().second;
		if(visited[boardToString(cur_board)]) {
			q.pop(); continue;	
		}
		visited[boardToString(cur_board)] = 1;
		
		q.pop();
		
		if(check_clean(cur_board)){
			answer = cnt_move;
			break;	
		}
		
		for(int i = 0; i < 3; i++){
			for(int k = 0; k < 3; k++){
				
				for(int j = 0; j < 4; j++){
					int ny = i + dir[0][j];
					int nx = k + dir[1][j];
				
					if(check_range(ny, nx) && cur_board[ny][nx] == 0){
						int tmp = cur_board[i][k];
						cur_board[ny][nx] = tmp;
						cur_board[i][k] = 0;
						
						if(visited.count(boardToString(cur_board)) == 0){
							q.push({cur_board, cnt_move + 1});
						}
						
						cur_board[ny][nx] = 0;
						cur_board[i][k] = tmp;
					}
				}
			}
		}
		
	}
	
	cout << answer;
}