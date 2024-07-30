#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void input();
void solve();
void bfs(int row, int col);

int N, M, picture_cnt, picture_size;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int map[501][501];
bool visit[501][501];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
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
	input();
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			if (map[r][c] == 1 && !visit[r][c]) {
				bfs(r, c);
				picture_cnt++;
			}
		}
	}
	cout << picture_cnt << "\n" << picture_size;
}

void bfs(int row, int col) {
	int cnt = 1;
	queue<pair<int, int>> Q;
	Q.push({ row, col });
	visit[row][col] = true;
	while (!Q.empty()) {
		pair<int, int> pos = Q.front();
		Q.pop();
		for (int d = 0; d < 4; ++d) {
			int nr = pos.first + dr[d];
			int nc = pos.second + dc[d];
			if (0 <= nr && nr < N && 0 <= nc && nc < M && map[nr][nc] == 1 && !visit[nr][nc]) {
				visit[nr][nc] = true;
				Q.push({ nr,nc });
				cnt++;
			}

		}
	}
	picture_size = cnt < picture_size ? picture_size : cnt;
}