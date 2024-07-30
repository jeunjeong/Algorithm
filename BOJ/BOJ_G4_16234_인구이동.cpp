#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void input();
void solve();
bool bfs(int row, int col);

int N, L, R,  ans;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int map[51][51];
bool visit[51][51];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N >> L >> R;
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < N; ++col) {
			cin >> map[row][col];
		}
	}
	return;
}

void solve() {
	input();
	bool flag = true;
	while (flag) {
		flag = false;
		for (int row = 0; row < N; ++row) {
			for (int col = 0; col < N; ++col) {
				if (!visit[row][col]) {
					if (bfs(row, col)) {
						if (!flag) {
							ans++;
							flag = true;
						}
					}
				}
			}
		}
		memset(visit, false, sizeof(visit));
	}
	cout << ans;
	return;
}

bool bfs(int row, int col) {
	int cnt = 0;
	int people = 0;
	bool section[51][51] = { false, };
	queue<pair<pair<int, int>,int>> Q;
	Q.push({ { row,col },map[row][col] });
	section[row][col] = true;
	visit[row][col] = true;
	cnt++;
	people += map[row][col];
	while (!Q.empty()) {
		pair<pair<int, int>,int> pos = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nr = pos.first.first + dr[dir];
			int nc = pos.first.second + dc[dir];
			if (0 <= nr && nr < N && 0 <= nc && nc < N && !visit[nr][nc]) {
				int gap = pos.second > map[nr][nc] ? pos.second - map[nr][nc] : map[nr][nc] - pos.second;
				if (L <= gap && gap <= R) {
					visit[nr][nc] = true;
					section[nr][nc] = true;
					Q.push({ {nr,nc},map[nr][nc] });
					cnt++;
					people += map[nr][nc];
				}
			}
		}
	}if (cnt > 1) {
		int after_move = people / cnt;
		for (int row = 0; row < N; ++row) {
			for (int col = 0; col < N; ++col) {
				if (section[row][col]) {
					map[row][col] = after_move;
				}
			}
		}
		return true;;
	}
	else {
		return false;
	}
}