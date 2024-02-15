#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct position {
	int row;
	int col;
	int brk;
};

int N, M, K, ans = 0;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
bool visit[1001][1001][11];
int map[1001][1001];

void input(void);
int bfs(void);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	if (N == 1 && M == 1) {
		cout << 1;
		return 0;
	}
	cout << bfs();
	return 0;
}

void input(void) {
	cin >> N >> M >> K;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			char buf;
			cin >> buf;
			map[r][c] = buf - 48;
		}
	}
	return;
}

int bfs(void) {
	int depth = 1;
	queue<position> Q;
	Q.push({ 0,0,0 });
	visit[0][0][0] = true;
	while (!Q.empty()) {
		depth++;
		int q_size = Q.size();
		for (int dep = 0; dep < q_size; ++dep) {
			position pos = Q.front();
			Q.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nr = pos.row + dr[dir];
				int nc = pos.col + dc[dir];
				if (0 <= nr && nr < N && 0 <= nc && nc < M) {
					if (map[nr][nc] == 1 && pos.brk < K && !visit[nr][nc][pos.brk + 1]) {// 다음 칸이 벽일 때 벽을 뚫을 수 있는 횟수가 남아있고, 방문하지 않은 곳이면?
						Q.push({ nr,nc,pos.brk + 1 });
						visit[nr][nc][pos.brk + 1] = true;
					}
					else if (map[nr][nc] == 0 && !visit[nr][nc][pos.brk]) { //벽이 아니고 방문하지 않은 곳이면?
						Q.push({ nr,nc,pos.brk });
						visit[nr][nc][pos.brk] = true;
						if (nr == N - 1 && nc == M - 1) {
							return depth;
						}

					}
				}
			}
		}
	}
	return -1;
}