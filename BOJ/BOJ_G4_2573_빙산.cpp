#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

void input();
void solve();
bool bfs();

int N, M, ans = 0;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int map[300][300];
bool visit[300][300];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	cout << ans;
	return 0;
}

void input() {
	cin >> N >> M;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			cin >> map[r][c];
		}
	}
}

void solve() {
	bool flag = true;
	int buf[300][300];
	for (int i = 1; i < 300; ++i) {
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < M; ++c) {
				if (map[r][c] == 0) {
					buf[r][c] = 0;
				}
				else {
					int cnt = 0;
					for (int d = 0; d < 4; ++d) {
						int nr = r + dr[d];
						int nc = c + dc[d];
						if (0 <= nr && nr < N && 0 <= nc && nc < M && map[nr][nc] == 0) {
							cnt++;
						}
					}
					buf[r][c] = (map[r][c] - cnt) > 0 ? map[r][c] - cnt : 0;
				}
			}
		}
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < M; ++c) {
				map[r][c] = buf[r][c];
			}
		}
		if (!bfs()) {
			ans = i;
			return;
		}
	}
	ans = 0;
	return;
}

bool bfs() {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> Q;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			if (map[r][c] != 0) {
				Q.push({ r,c });
				visit[r][c] = true;
				c = M;
				r = N;
			}
		}
	}
	while (!Q.empty()) {
		pair<int, int> pos = Q.front();
		Q.pop();
		for (int d = 0; d < 4; ++d) {
			int nr = pos.first + dr[d];
			int nc = pos.second + dc[d];
			if (0 <= nr && nr < N && 0 <= nc && nc < M && !visit[nr][nc] && map[nr][nc] != 0) {
				visit[nr][nc] = true;
				Q.push({ nr,nc });
			}
		}
	}
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			if (map[r][c] != 0 && !visit[r][c]) {
				return false;
			}
		}
	}
	return true;
}