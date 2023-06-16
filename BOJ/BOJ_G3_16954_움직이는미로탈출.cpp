#include <iostream>
#include <queue>

#define endl '\n'
#define MAX 8

using namespace std;

int d_row[] = {-1,-1, 0, 1, 1, 1, 0,-1,0};
int d_col[] = { 0, 1, 1, 1, 0,-1,-1,-1,0};
char map[MAX][MAX];
//플레이어 위치
pair<int, int> player = {7, 0};

bool possible(int row, int col);
int bfs();
void shift();


int main(void){
    for(int i = 0; i < MAX; ++i){
        for(int j = 0; j < MAX; ++j){
            cin >> map[i][j];
        }
    }
    int ans = bfs();
    cout << ans;
}

void shift(){
    for(int i = 6; i >= 0; --i){
        for(int j = 0; j < MAX; ++j){
            map[i+1][j] = map[i][j];
        }
    }
    for(int i = 0; i < MAX; ++i){
        map[0][i] = '.';
    }
}

int bfs(){
    queue<pair<int,int>> que;
    que.push(player);
    while(!que.empty()){
        int siz = que.size();
        for(int i = 0; i < siz; ++i){
            pair<int,int> now = que.front();
            que.pop();
            int nr = now.first;
            int nc = now.second;
            for(int j = 0; j < 9; ++j){
                nr = now.first + d_row[j];
                nc = now.second + d_col[j];
                //cout << nr << "  :  " << nc << endl;
                if(possible(nr,nc)){

                    //cout << "nr : " << nr << " && nc :" << nc << endl;
                    if(nr == 0 && nc == 7) return 1;
                    que.push({nr,nc});
                }
            }
        }
        shift();
    }
    return 0;
}

bool possible(int row, int col){
    if(0 <= row && row < MAX && 0 <= col && col < MAX && map[row][col] == '.'){
        if(row != 0 && map[row-1][col] == '#') return false;
        return true;
    }
    return false;
}
