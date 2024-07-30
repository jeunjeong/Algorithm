#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void input();
void solve();
void bfs();

int N, M, ans;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int map[100][100];
bool visit[100][100];

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
		string str;
		cin >> str;
		for (int c = 0; c < M; ++c) {
			map[r][c] = str[c] - '0';
		}
	}
	return;
}

void solve() {
	input();
	bfs();
	cout << ans+2;
	return;
}

void bfs() {
	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	visit[0][0] = true;
	while (!Q.empty()) {
		int siz = Q.size();
		for (int s = 0; s < siz; ++s) {
			pair<int, int> pos = Q.front();
			Q.pop();
			for (int d = 0; d < 4; ++d) {
				int nr = pos.first + dr[d];
				int nc = pos.second + dc[d];
				if (0 <= nr && nr < N && 0 <= nc && nc < M && !visit[nr][nc] && map[nr][nc] == 1) {
					visit[nr][nc] = true;
					Q.push({ nr,nc });
					if (nr == N - 1 && nc == M - 1) {
						return;
					}
				}

			}
		}
		ans++;
	}
}