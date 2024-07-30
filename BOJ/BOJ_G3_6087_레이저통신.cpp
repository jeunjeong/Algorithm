#include <iostream>
#include <queue>

#define endl '\n'
#define MAX 100
using namespace std;

int W, H;
int d_row[] = {-1, 0, 1, 0};
int d_col[] = { 0, 1, 0,-1};
char map[MAX][MAX];
int visit[MAX][MAX];

pair<int, int> Start, End;

int bfs();

int main(void){
    cin >> W >> H;
    bool C_cnt=false;
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
            cin >> map[i][j];
            if(map[i][j] == 'C'){
                if(!C_cnt){
                    C_cnt = true;
                    Start = {i,j};
                }else{
                    End = {i,j};
                }
            }
            visit[i][j] = 10000;
        }
    }
//    cout << "start : " << Start.first << ", " << Start.second << endl;
//    cout << "end : " << End.first << ", " << End.second << endl; 
    int res = bfs();
    cout << res;
    return 0;
}

int bfs(){
    //row, col, dir, cnt
    queue<pair<pair<int,int>, pair<int, int>>> que;
    for(int i = 0; i < 4; ++i){ 
        que.push({Start, {i,0}});
    }
    while(!que.empty()){
        pair<pair<int,int>, pair<int, int>> x = que.front();
        que.pop();
        int row = x.first.first;
        int col = x.first.second;
        int dir = x.second.first;
        int cnt = x.second.second;
        for(int i = 0; i < 4; ++i){
            int nr = row + d_row[i];
            int nc = col + d_col[i];
            //cout << nr << " : " << nc << endl;
            if(nr < 0 || nr >= H || nc < 0 || nc >= W || map[nr][nc] == '*') continue;
            if(dir != i){ //방향전환을 했을 때
                if(visit[nr][nc] >= cnt+1){
                    que.push({{nr,nc},{i,cnt+1}});
                    visit[nr][nc] = cnt+1;
                }
            }else{ //방향전환을 안했을 때
                if(visit[nr][nc] >= cnt){
                    que.push({{nr,nc},{i,cnt}});
                    visit[nr][nc] = cnt;
                }
            }
        }
    }
    return visit[End.first][End.second];
}
