#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, K, R, ans = 0;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int map[101][101][4];
bool visit[101][101] = { false, };
vector<pair<int, int>> cow;

void input();
void solve();
void bfs(pair<int, int> start, pair<int, int> end);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}

void input() {
	cin >> N >> K >> R;
	pair<int, int> pos1, pos2;
	for (int r = 0; r < R; ++r) {
		cin >> pos1.first >> pos1.second >> pos2.first >> pos2.second;
		for (int i = 0; i < 4; ++i) {
			if (pos1.first + dr[i] == pos2.first && pos1.second + dc[i] == pos2.second) {
				map[pos1.first][pos1.second][i] = 1;
				map[pos2.first][pos2.second][(i + 2) % 4] = 1;
				break;
			}
		}
	}
	for (int k = 0; k < K; ++k) {
		cin >> pos1.first >> pos1.second;
		cow.push_back(pos1);
	}
}

void solve() {
	for (int i = 0; i < K; ++i) {
		for (int j = i+1; j < K; ++j) {
			memset(visit, false, sizeof(visit));
			//cout << cow[i].first << ":" << cow[i].second << "||" << cow[j].first << ":" << cow[j].second << "\n";
			bfs(cow[i], cow[j]);
		}
	}
	cout << ans;
}

void bfs(pair<int, int> start, pair<int, int> end) {
	queue<pair<int, int>> Q;
	Q.push(start);
	while (!Q.empty()) {
		pair<int, int> pos = Q.front();
		Q.pop();
		int row = pos.first;
		int col = pos.second;
		for (int dir = 0; dir < 4; ++dir) {
			int nr = row + dr[dir];
			int nc = col + dc[dir];
			if (0 < nr && nr <= N && 0 < nc && nc <= N && !visit[nr][nc] && map[row][col][dir] == 0) { // 범위안에 있고, 갈 수 있는 길이면 ..? 
				//cout << nr << ":" << nc << '\n';
				if (nr == end.first && nc == end.second) {
					return;
				}
				visit[nr][nc] = true;
				Q.push({ nr,nc });
			}
		}
	}
	ans += 1;
	return;
}