#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int R, C, M;
int ans;

int dirY[5] = {0, -1, 1, 0, 0};
int dirX[5] = {0, 0, 0, 1, -1};

struct fish{
    int size;
    int speed;
    int dir;
    bool live;
};

vector<fish> board[101][101];
vector<fish> c_board[101][101];

void copy_board(){
    for(int i = 0; i < R; i++){
        for(int k = 0; k < C; k++){
            c_board[i][k].clear();
            c_board[i][k] = board[i][k];
        }
    }
}

bool custom_compare(fish f1, fish f2){
    if(f1.size >= f2.size) return true;
    return false;
}

void fishing(int king_idx){
    bool flag = false;

    for(int i = 0; i < R; i++){
        for(int k = 0; k < board[i][king_idx].size(); k++){
            if(board[i][king_idx][k].live){
                board[i][king_idx][k].live = false;
                ans += board[i][king_idx][k].size;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
}

// 상어 이동
void move_shark(){ 
    
    copy_board();

    for(int i = 0; i < R; i++){
        for(int k = 0; k < C; k++){

            int bs = c_board[i][k].size();

            for(int j = 0; j < bs; j++){
                // live보다 erase가 더 나을려나
                if(board[i][k][j].live){
                    board[i][k][j].live = false;
                    int c_dir = board[i][k][j].dir;
                    int c_size = board[i][k][j].size;
                    int c_speed = board[i][k][j].speed;
                    int cy = i, cx = k;

                    // 위, 아래인 경우는 t = 2 * (R - 1)을 하면 원래 위치로 돌아온다.
                    // 속도 % t 모듈러 연산을 통해 최대 2 * (R - 1) 이동만 구해주면 된다.
                    if(c_dir == 1 || c_dir == 2){
                        int s = c_speed % (2 * (R - 1));

                        while(s--){
                            cy = cy + dirY[c_dir];

                            if(cy >= R){
                                cy = R - 2; // -2로 해줘야됨 1시간만에 찾음..
                                c_dir = 1;
                            }
                            else if(cy < 0){
                                cy = 1;
                                c_dir = 2;
                            }
                        }
                    }

                    else if(c_dir == 3 || c_dir == 4){
                        int s = c_speed % (2 * (C - 1));

                        while(s--){
                            cx = cx + dirX[c_dir];

                            if(cx >= C){
                                cx = C - 2;
                                c_dir = 4;
                            }
                            else if(cx < 0){
                                cx = 1;
                                c_dir = 3;
                            }
                        }
                    }

                    fish f;
                    f.dir = c_dir;
                    f.size = c_size;
                    f.speed = c_speed;
                    f.live = true;

                    board[cy][cx].push_back(f);

                }
            }

        }
    }
}

// 상어 잡아먹기
void eat_shark(){
    for(int i = 0; i < R; i++){
        for(int k = 0; k < C; k++){
            sort(board[i][k].begin(), board[i][k].end(), custom_compare);

            bool flag = false;
            fish f;
            
            // 최초로 살아있는 상어를 제외한 나머지 상어를 죽인다.
            for(int j = 0; j < board[i][k].size(); j++){
                if(board[i][k][j].live) {
                    f = board[i][k][j];
                    board[i][k].clear();
                    board[i][k].push_back(f);
                    break;
                }
            }
        }
    }
}



int main(){
    cin >> R >> C >> M;

    for(int i = 0; i < M; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;

        fish f;
        f.speed = s;
        f.dir = d;
        f.size = z;
        f.live = true;

        board[r - 1][c - 1].push_back(f);
    }

    int king_idx = -1;

    while(++king_idx < C){
        fishing(king_idx);
        move_shark();
        eat_shark();
    }

    cout << ans;
}