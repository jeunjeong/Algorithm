#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void input();
void solve();
void bfs();

int N, M, K;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int map[100][100];
bool visit[100][100];
vector<int> ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i) {
		int r1, r2, c1, c2;
		cin >> c1 >> r1 >> c2 >> r2;
		for (int r = r1; r < r2; ++r) {
			for (int c = c1; c < c2; ++c) {
				map[r][c] = 1;
			}
		}
	}
	return;
}

void solve() {
	input();
	bfs();
	int siz = ans.size();
	cout << siz << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < siz; ++i) {
		cout << ans[i] << ' ';
	}
	return;
}

void bfs() {
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			if (map[r][c] == 0 && !visit[r][c]) {
				queue<pair<int, int>> Q;
				Q.push({ r,c });
				visit[r][c] = true;
				int cnt = 1;
				while (!Q.empty()) {
					pair<int, int> pos = Q.front();
					Q.pop();
					for (int d = 0; d < 4; ++d) {
						int nr = pos.first + dr[d];
						int nc = pos.second + dc[d];
						if (0 <= nr && nr < N && 0 <= nc && nc < M && map[nr][nc] == 0 && !visit[nr][nc]) {
							visit[nr][nc] = true;
							Q.push({ nr,nc });
							cnt++;
						}
					}
				}
				ans.push_back(cnt);
			}
		}
	}
	return;
}