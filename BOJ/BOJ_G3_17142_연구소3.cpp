#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();
void combination(int n, int idx);
void bfs();
bool check(bool visit[50][50]);

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int N, M, ans = 1000001;
int map[50][50];
bool visit[50][50];
bool virus[10] = { false, };
vector<pair<int, int>> pos;
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
				pos.push_back({ r,c });
			}
		}
	}
	return;
}

void solve() {
	input();
	if (check(visit)) ans = 0;
	else {
		combination(0, 0);
	}
	if (ans == 1000000) ans = -1;
	cout << ans;
	return;
}

void combination(int n, int idx) {
	if (n == M) {
		while (!Q.empty()) Q.pop();
		for (int i = 0; i < 10; ++i) {
			if (virus[i]) {
				//cout << pos[i].first << " : " << pos[i].second << '\n';
				Q.push({ pos[i].first,pos[i].second });
			}
		}
		//cout << '\n';
		bfs();
		return;
	}
	for (int i = idx; i < pos.size(); ++i) {
		if (!virus[i]) {
			virus[i] = true;
			combination(n + 1, i + 1);
			virus[i] = false;
		}
	}
}

void bfs() {
	int T = 0;
	memset(visit, false, sizeof(visit));
	while (!Q.empty() && T < ans) {
		int siz = Q.size();
		bool flag = true;
		for (int i = 0; i < siz; ++i) {
			pair<int, int> position = Q.front();
			Q.pop();
			visit[position.first][position.second] = true;
			for (int d = 0; d < 4; ++d) {
				int nr = position.first + dr[d];
				int nc = position.second + dc[d];
				if (0 <= nr && nr < N && 0 <= nc && nc < N && !visit[nr][nc] && map[nr][nc] != 1) {
					if (flag && map[nr][nc] == 0) flag = false;
					Q.push({ nr,nc });
					visit[nr][nc] = true;
				}
			}
		}
		if (flag && check(visit)) break;
		else T++;
	}
	if (!check(visit)) T = 1000000;
	//cout << T << '\n';
	T < ans ? ans = T : ans;
	return;
}

bool check(bool visit[50][50]) {
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N;++c) {
			if (!visit[r][c] && map[r][c] == 0) {
				return false;
			}
		}
	}
	return true;
}