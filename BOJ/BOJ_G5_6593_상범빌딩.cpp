#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct pos {
	int h;
	int r;
	int c;

};

void input();
void solve();
bool bfs();

bool visit[30][30][30];
char map[30][30][30];
int L, R, C, ans;
int dr[6] = { -1, 1, 0, 0, 0, 0 };
int dc[6] = { 0, 0, -1, 1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, -1, 1 };
pos start, finish;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> L >> R >> C;
	string str;
	for (int h = 0; h < L; ++h) {
		for (int r = 0; r < R; ++r) {
			cin >> str;
			for (int c = 0; c < C; ++c) {
				map[h][r][c] = str[c];
				if (map[h][r][c] == 'S') start = { h,r,c };
				else if (map[h][r][c] == 'E') {
					finish = { h,r,c };
					map[h][r][c] = '.';
				}
			}
		}
	}
	return;
}

void solve() {
	while (true) {
		ans = 1;
		memset(visit, false, sizeof(visit));
		memset(map, false, sizeof(map));
		input();
		if (L == 0 && R == 0 && C == 0) return; //종료조건
		if (bfs()) cout << "Escaped in " << ans << " minute(s).\n";
		else cout << "Trapped!\n";
	}
}

bool bfs() {
	queue<pos> Q;
	Q.push(start);
	visit[start.h][start.r][start.c] = true;
	while (!Q.empty()) {
		int siz = Q.size();
		for (int s = 0; s < siz; ++s) {
			pos x = Q.front();
			Q.pop();
			for (int d = 0; d < 6; ++d) {
				int nh = x.h + dh[d];
				int nr = x.r + dr[d];
				int nc = x.c + dc[d];
				if (0 <= nh && nh < L && 0 <= nr && nr < R && 0 <= nc && nc < C && map[nh][nr][nc] == '.' && !visit[nh][nr][nc]) {
					if (nh == finish.h && nr == finish.r && nc == finish.c) return true;
					Q.push({ nh,nr,nc });
					visit[nh][nr][nc] = true;
				}
			}
		}
		ans++;
	}
	return false;
}