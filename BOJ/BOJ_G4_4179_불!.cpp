#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void input();
void solve();

int R, C, ans = 0;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
char map[1000][1000];
bool visit[1000][1000];
bool visit_J[1000][1000];
queue<pair<int, int>> fire;
queue<pair<int, int>> J;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}

void input() {
	cin >> R >> C;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			char x;
			cin >> x;
			if (x == 'J') {
				J.push({ r,c });
				map[r][c] = '.';
				visit_J[r][c] = true;
			}
			else if (x == 'F') {
				fire.push({ r,c });
				map[r][c] = x;
				visit[r][c] = true;
			}
			else {
				map[r][c] = x;
			}

		}
	}
}

void solve() {
	while (!J.empty() || !fire.empty()) {
		ans++;
		int size = fire.size();
		for (int s = 0; s < size; ++s) {
			pair<int, int> pos = fire.front();
			fire.pop();
			for (int d = 0; d < 4; ++d) {
				int nr = pos.first + dr[d];
				int nc = pos.second + dc[d];
				if (0 <= nr && nr < R && 0 <= nc && nc < C && map[nr][nc] == '.' && !visit[nr][nc]) {
					fire.push({ nr,nc });
					visit[nr][nc] = true;
					map[nr][nc] = 'F';
				}
			}
		}
		size = J.size();
		for (int s = 0; s < size; ++s) {
			pair<int, int> pos = J.front();
			J.pop();
			for (int d = 0; d < 4; ++d) {
				int nr = pos.first + dr[d];
				int nc = pos.second + dc[d];
				if (0 <= nr && nr < R && 0 <= nc && nc < C) {
					if (map[nr][nc] != '#' && map[nr][nc] != 'F' && !visit_J[nr][nc]) {
						visit_J[nr][nc] = true;
						J.push({ nr,nc });
					}
				}
				else { // 범위 밖으로 나가면 탈출
					cout << ans;
					return;
				}
			}
		}
	}
	cout << "IMPOSSIBLE";
	return;
}