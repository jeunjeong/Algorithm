#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void input();
void solve();
void combination(int idx, int  n);
void bfs();
bool check();

int N, M, cnt_virus, ans = 10000;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int map[51][51];
bool visit[51][51];
bool virus[11];
pair<int, int> virus_pos[11];
queue<pair<int, int>> Q;

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
		for (int c = 0; c < N; ++c) {
			cin >> map[r][c];
			if (map[r][c] == 2) {
				virus_pos[cnt_virus] = { r,c };
				cnt_virus++;
			}
		}
	}
	return;
}

void solve() {
	input();
	combination(0, 0);
	ans = (ans == 10000 ? -1 : ans);
	cout << ans;
	return;
}

void combination(int idx, int  n) {
	if (n == M) {
		while (!Q.empty()) Q.pop();
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < cnt_virus; ++i) {
			if (virus[i]) {
				Q.push(virus_pos[i]);
				visit[virus_pos[i].first][virus_pos[i].second] = true;
			}
		}
		bfs();
		return;
	}
	for (int i = idx; i < cnt_virus; ++i) {
		if (!virus[i]) {
			virus[i] = true;
			combination(i, n + 1);
			virus[i] = false;
		}
	}
	return;
}

void bfs() {
	int tim = -1;
	while (!Q.empty()) {
		int siz = Q.size();
		for (int i = 0; i < siz; ++i) {
			pair<int, int> pos = Q.front();
			Q.pop();
			for (int d = 0; d < 4; ++d) {
				int nr = pos.first + dr[d];
				int nc = pos.second + dc[d];
				if (0 <= nr && nr < N && 0 <= nc && nc < N && !visit[nr][nc] && map[nr][nc] != 1) {
					visit[nr][nc] = true;
					Q.push({ nr,nc });
				}
			}
		}
		tim++;
	}
	if (check()) {
		ans = ans < tim ? ans : tim;
	}

	return;
}

bool check() {
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			if (!visit[r][c] && map[r][c] != 1) return false;
		}
	}
	return true;
}
