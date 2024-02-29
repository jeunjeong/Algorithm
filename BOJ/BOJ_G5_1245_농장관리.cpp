#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

void input();
void solve();
void bfs(pair<int,int> start, int height);

int N, M, ans;
int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int map[100][70];
bool visit[100][70];
bool check[100][70];

int main() {
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
			if (!check[r][c] && map[r][c] > 0) {
				pair<int, int> pos = { r,c };
				bfs(pos, map[r][c]);
			}
		}
	}
	cout << ans;
}
void bfs(pair<int, int> start, int height) {
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> Q;
	Q.push(start);
	visit[start.first][start.second] = true;
	while (!Q.empty()) {
		pair<int, int> pos = Q.front();
		Q.pop();
		for (int d = 0; d < 8; ++d) {
			int nr = pos.first + dr[d];
			int nc = pos.second + dc[d];
			if (0 <= nr && nr < N && 0 <= nc && nc < M && !visit[nr][nc]) {
				if (map[nr][nc] > height) {
					return;
				}
				else if (map[nr][nc] == height) {
					Q.push({ nr,nc });
					check[nr][nc] = true;
					visit[nr][nc] = true;
				}
			}
		}
	}
	ans++;
}