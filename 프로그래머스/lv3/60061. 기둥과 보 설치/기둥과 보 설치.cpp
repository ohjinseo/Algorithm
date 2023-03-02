#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#define t tuple<int, int, int>
#include <tuple>
#include <set>

using namespace std;

bool structs[101][101][2];
set<t> s;

bool cmp(vector<int> a, vector<int> b){
    int ay, ax, akind, by, bx, bkind;
    
    ax = a[0], ay = a[1], akind = a[2];
    bx = b[0], by = b[1], bkind = b[2];
    
    if(ax < bx) return true;
    else if(ax == bx && ay < by) return true;
    else if(ax == bx && ay == by && akind < bkind) return true;
    
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for(int i = 0; i < build_frame.size(); i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        
        int kind = build_frame[i][2];
        int type = build_frame[i][3];
        
        // 설치
        if(type == 1){
            // 기둥
            if(kind == 0){
                // 바닥 or 보의 한쪽 끝 or 밑에 기둥이 있는지
                if(y == 0 || (structs[y][x][1] || structs[y][x-1][1]) || structs[y - 1][x][0]){
                    structs[y][x][kind] = true;
                    s.insert({y, x, kind});
                }
            }
            // 보
            else{
                // 보를 설치할 위치의 한쪽 끝에 기둥이 있거나, 양쪽에 보가 있거나
                if((structs[y - 1][x][0] || structs[y - 1][x + 1][0]) || (structs[y][x-1][1] && structs[y][x+1][1])){
                    structs[y][x][kind] = true;
                    s.insert({y, x, kind});
                }
            }
        }
        // 삭제
        else{
            structs[y][x][kind] = false;
            bool flag = true;
            
            for(int i = 0; i <= n; i++){
                for(int k = 0; k <= n; k++){
                    for(int j = 0; j < 2; j++){
                        if(structs[i][k][j]){
                            
                            // 기둥이라면
                            if(j == 0){
                                if(i == 0 || (structs[i][k][1] || structs[i][k-1][1]) || structs[i - 1][k][0]){
                                    continue;
                                }else{
                                    flag = false;
                                    break;
                                }
                            }
                            // 보라면
                            else{
                                if((structs[i - 1][k][0] || structs[i - 1][k + 1][0]) || (structs[i][k-1][1] && structs[i][k+1][1])){
                                    continue;
                                }else{
                                    flag = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if(!flag) structs[y][x][kind] = true;
        }
        
        
    }

    
    for(int i = 0; i <= n; i++){ // x 좌표
        for(int k = 0; k <= n; k++){ // y 좌표
            for(int j = 0; j < 2; j++){
                if(structs[k][i][j]){
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(k);
                    tmp.push_back(j);
                    
                    answer.push_back(tmp);
                }
            }
        }
    }
    
    return answer;
}