#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void input();
void solve();
int bfs(int index);

int N, M, P, ans;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
pair<pair<int, int>, int> boss; // r, c, hp
pair<pair<int, int>, int> players[27];
bool visit[1001][1001];
char map[1001][1001] = { '.', };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> M >> N >> P;
	for (int r = 0; r < M; ++r) {
		string str;
		cin >> str;
		for (int c = 0; c < N; ++c) {
			map[r][c] = str[c];
			if (map[r][c] == 'B') boss.first = { r, c };
			else if ('a' <= map[r][c] && map[r][c] <= 'z') {
				players[map[r][c] - 'a'].first = { r, c };
			}
		}
	}
	char a; int b;
	for (int player = 0; player < P; ++player) {
		cin >> a >> b;
		players[player].second = b;
	}
	cin >> boss.second;
	return;
}

void solve() {
	input();
	int distance[26] = { 0, };
	for (int player = 0; player < P; ++player) {
		memset(visit, false, sizeof(visit));
		distance[player] = bfs(player);
	}
	while (boss.second > 0) {
		for (int player = 0; player < P; ++player) {
			if (distance[player] > 1) distance[player] --;
			else {
				boss.second -= players[player].second;
				if (distance[player] == 1) {
					ans++;
					distance[player] = 0;
				}
			}
		}
	}
	cout << ans;
	return;
}

int bfs(int index) {
	int level = 0;
	queue<pair<int, int>> Q;
	Q.push(players[index].first);
	visit[players[index].first.first][players[index].first.second] = true;
	while (!Q.empty()) {
		level++;
		int siz = Q.size();
		for (int s = 0; s < siz; ++s) {
			pair<int, int> pos = Q.front();
			Q.pop();
			for (int d = 0; d < 4; ++d) {
				int nr = pos.first + dr[d];
				int nc = pos.second + dc[d];
				if (0 <= nr && nr < M && 0 <= nc && nc < N && map[nr][nc] != 'X' && !visit[nr][nc]) {
					visit[nr][nc] = true;
					Q.push({ nr,nc });
					if (map[nr][nc] == 'B') { return level; }
				}
			}
		}
	}
	return 1000000;
}