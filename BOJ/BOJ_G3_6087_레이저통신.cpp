#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Pos {
    int row;
    int col;
    int dir;
    int mirror;
};
int R, C;
pair<int, int> start, finish;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
char map[101][101];
int visit[101][101];

void input();
void solve();
void bfs();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

void input() {
    bool flag = false;
    cin >> C >> R;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> map[r][c];
            if (map[r][c] == 'C') {
                if (!flag) {
                    start = { r,c };
                    flag = true;
                }
                else finish = { r,c };
                map[r][c] = '.';
            }
        }
    }
}

void solve() {
    fill(&visit[0][0], &visit[100][100], 10000);
    input();
    bfs();
    cout << visit[finish.first][finish.second];
}

void bfs() {
    queue<Pos> Q;
    for (int d = 0; d < 4; ++d) {
        int nr = start.first + dr[d];
        int nc = start.second + dc[d];
        if (nr == finish.first && nc == finish.second) {
            visit[finish.first][finish.second] = 0;
            return;
        }
        else if (0 <= nr && nr < R && 0 <= nc && nc < C && map[nr][nc] == '.') {
            visit[start.first][start.second] = -1;
            Q.push({ nr,nc,d,0 }); 
        }
    }
    while (!Q.empty()) {
        Pos x = Q.front();
        Q.pop();
        for (int d = 0; d < 4; ++d) {
            if (x.dir == 0 && d == 1)continue;
            else if (x.dir == 1 && d == 0) continue;
            else if (x.dir == 2 && d == 3) continue;
            else if (x.dir == 3 && d == 2) continue;
            int nr = x.row + dr[d];
            int nc = x.col + dc[d];
            if (0 <= nr && nr < R && 0 <= nc && nc < C && map[nr][nc] == '.') {
                //cout << nr << ":" << nc << "&&" << x.dir << ":" << d << "&& mirror" << visit[nr][nc] << ":" << x.mirror << '\n';
                if (visit[nr][nc] >= x.mirror && (x.dir == 0 || x.dir == 1) && (d == 0 || d == 1)) { //방향을 안꺾을때는
                    visit[nr][nc] = x.mirror;
                    Q.push({ nr, nc, d, x.mirror }); 
                }
                else if (visit[nr][nc] > x.mirror && (x.dir == 2 || x.dir == 3) && (d == 2 || d == 3)) {
                    visit[nr][nc] = x.mirror;
                    Q.push({ nr, nc, d, x.mirror });
                }
                else if (visit[nr][nc] > x.mirror) { //방향을꺾을때는?
                    visit[nr][nc] = x.mirror+1;
                    Q.push({ nr, nc, d, x.mirror +1});
                }
            }
        }
    }
    return;
}