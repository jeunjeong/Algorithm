#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void input();
void solve();
void bfs();

int TC, N, M, K, ans;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int map[50][50];
bool visit[50][50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> M >> N >> K;
	for (int i = 0; i < K; ++i) {
		int r, c;
		cin >> c >> r;
		map[r][c] = 1;
	}
}

void solve() {
	cin >> TC;
	for (int test_case = 0; test_case < TC; ++test_case) {
		memset(visit, false, sizeof(visit));
		memset(map, 0, sizeof(map));
		ans = 0;
		input();
		bfs();
		cout << ans << '\n';
	}
}

void bfs() {
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			if (map[r][c] == 1 && !visit[r][c]) {
				ans++;
				queue<pair<int, int>> Q;
				Q.push({ r,c });
				visit[r][c] = true;
				while (!Q.empty()) {
					pair<int, int> pos = Q.front();
					Q.pop();
					for (int d = 0; d < 4; ++d) {
						int nr = pos.first + dr[d];
						int nc = pos.second + dc[d];
						if (0 <= nr && nr < N && 0 <= nc && nc < M && !visit[nr][nc] && map[nr][nc] == 1) {
							visit[nr][nc] = true;
							Q.push({ nr,nc });
						}
					}
				}
			}
		}
	}
	
}