#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void input();
void solve();
bool bfs();
void shift();

#define R 12
#define C 6
int ans = 0;
char map[R][C];
bool visit[R][C] = { false, };
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}
void input() {
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cin >> map[r][c];
		}
	}
}

void solve() {
	bool flag = true;
	while (flag) {
		flag = bfs();
		memset(visit, false, sizeof(visit));
		shift();
		if(flag) ans++;
	}
	cout << ans;
}

bool bfs() {
	bool flag = false;
	for (int r = 0; r < R; ++r) { 
		for (int c = 0; c < C; ++c) { // ¿µ¿ª Å½Áö
			if (map[r][c] == '.') {
				visit[r][c] = true;
;			}
			else {
				char state = map[r][c];
				int count = 1;
				queue<pair<int, int>> Q;
				vector<pair<int, int>> vec;
				vec.push_back({ r,c });
				Q.push({ r,c });
				visit[r][c] = true;
				while (!Q.empty()) {
					pair<int, int> pos = Q.front();
					Q.pop();
					int row = pos.first;
					int col = pos.second;
					for (int dir = 0; dir < 4; ++dir) {
						int nr = row + dr[dir];
						int nc = col + dc[dir];
						if (0 <= nr && nr < R && 0 <= nc && nc < C && !visit[nr][nc] && map[nr][nc] == state) {
							visit[nr][nc] = true;
							count += 1;
							vec.push_back({ nr,nc });
							Q.push({ nr,nc });
						}
					}
				}
				if (count >= 4) {
					int size = vec.size();
					for(int i = 0; i < size; ++i){
						pair<int, int> pos = vec[i];
						map[pos.first][pos.second] = '.';
					}
					if (!flag) {
						flag = true;
					}
				}
			}
		}
	}
	return flag;
}

void shift() {
	for (int r = R-2; r >= 0 ; --r) {
		for (int c = 0; c < C; ++c) {
			if (map[r][c] != '.') {
				int nr = r + 1;
				if (nr < R && map[nr][c] == '.') {
					while (nr+1 < R && map[nr+1][c] == '.') {
						nr += 1;
					}
					map[nr][c] = map[r][c];
					map[r][c] = '.';
				}A
			}
		}
	}
	
}
