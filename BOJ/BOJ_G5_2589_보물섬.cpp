#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void input();
void solve();
int bfs(pair<int, int> p);

int L, W, ans;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
vector<pair<int, int>> pos;
char map[50][50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	cout << ans;
	return 0;
}

void input() {
	cin >> L >> W;
	for (int r = 0; r < L; ++r) {
		for (int c = 0; c < W; ++c) {
			cin >> map[r][c];
			if (map[r][c] == 'L') {
				pos.push_back({ r,c });
			}
		}
	}
}

void solve() {
	for (int x = 0; x < pos.size(); ++x) {
		int cnt = bfs(pos[x]);
		ans = (ans > cnt ? ans : cnt);
	}
}


int bfs(pair<int, int> p) {
	int cnt = 0;
	bool visit[50][50] = { false, };
	visit[p.first][p.second] = true;
	queue <pair<int, int>> Q;
	Q.push(p);
	while (!Q.empty()) {
		int size = Q.size();
		for (int s = 0; s < size; ++s) {
			pair<int, int> popp = Q.front();
			Q.pop();
			for (int d = 0; d < 4; ++d) {
				int nr = popp.first + dr[d];
				int nc = popp.second + dc[d];
				if (0 <= nr && nr < L && 0 <= nc && nc < W && map[nr][nc] == 'L' && !visit[nr][nc]) {
					Q.push({ nr,nc });
					visit[nr][nc] = true;
				}
			}
		}
		if (!Q.empty()) {

			cnt++;
		}
	}
	//cout << p.first << " : " << p.second << " && cnt : " << cnt << '\n';
	return cnt;
}