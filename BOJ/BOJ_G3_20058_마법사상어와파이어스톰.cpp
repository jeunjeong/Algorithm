#include <iostream>
#include <queue>
#include <cmath>

#define MAX 65

using namespace std;

void input();
void solve();
void turn(int x);
void ice();
void ans();

int N, Q, siz;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int L[1001];
int map[MAX][MAX];
int buf[MAX][MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N >> Q;
	siz = pow(2, N);
	for (int row = 0; row < siz; ++row) {
		for (int col = 0; col < siz; ++col) {
			cin >> map[row][col];
		}
	}
	for (int idx = 0; idx < Q; ++idx) {
		cin >> L[idx];
	}
	return;
}

void solve() {
	input();
	for (int tc = 0; tc < Q; ++tc) {
		turn(L[tc]);
		ice();
	}
	ans();
	return;
}

void turn(int x) {
	int repeat = pow(2, N - x);
	int section = pow(2, x);
	for (int i = 0; i < repeat; ++i) {
		for (int row = 0; row < section; ++row) {
			for (int j = 0; j < repeat; ++j) {
				for (int col = 0; col < section; ++col) {
					buf[section * i + col][section * j + section - 1 - row] = map[section * i + row][section * j + col];
				}
			}
		}
	}
	for (int row = 0; row < siz; ++row) {
		for (int col = 0; col < siz; ++col) {
			map[row][col] = buf[row][col];
		}
	}
	return;
}

void ice() {
	for (int row = 0; row < siz; ++row) {
		for (int col = 0; col < siz; ++col) {
			int cnt = 0;
			for (int dir = 0; dir < 4; ++dir) {
				int nr = row + dr[dir];
				int nc = col + dc[dir];
				if (0 <= nr && nr < siz && 0 <= nc && nc < siz && map[nr][nc] > 0) {
					cnt++;
				}
			}
			if (cnt < 3 && map[row][col] > 0) {
				buf[row][col] = map[row][col] - 1;
			}
			else {
				buf[row][col] = map[row][col];
			}
		}
	}

	for (int row = 0; row < siz; ++row) {
		for (int col = 0; col < siz; ++col) {
			map[row][col] = buf[row][col];
		}
	}
	return;
}

void ans() {
	int ice_cnt = 0; //얼음 합
	int ice_siz = 0; //면적 
	bool visit[64][64] = { false, };
	for (int row = 0; row < siz; ++row) {
		for (int col = 0; col < siz; ++col) {
				ice_cnt += map[row][col];
			if (!visit[row][col] && map[row][col] > 0) {
				int cnt = 1;
				queue<pair<int, int>>Q;
				Q.push({ row,col });
				visit[row][col] = true;
				while (!Q.empty()) {
					pair<int, int> pos = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; ++dir) {
						int nr = pos.first + dr[dir];
						int nc = pos.second + dc[dir];
						if (0 <= nr && nr < siz && 0 <= nc && nc < siz && !visit[nr][nc] && map[nr][nc] > 0) {
							visit[nr][nc] = true;
							cnt++;
							Q.push({ nr,nc });
						}
					}
				}
				ice_siz = ice_siz > cnt ? ice_siz : cnt;
			}
		}
	}
	cout << ice_cnt << '\n' << ice_siz << '\n';
	return;
}