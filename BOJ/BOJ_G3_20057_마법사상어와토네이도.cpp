#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();
void bfs();

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { -1, 0, 1, 0 };
float move_data[4][5][5] = { { {0,0,0.02,0,0},{0,0.1,0.07,0.01,0},{0.05, -1, 0, 0, 0},  {0,0.1,0.07,0.01,0},{0,0,0.02,0,0} },
						{ {0,0,0,0,0},   {0,0.01,0,0.01,0},  {0.02,0.07,0,0.07,0.02},{0,0.1,-1,0.1,0}, {0,0,0.05,0,0} },
						{ {0,0,0.02,0,0},{0,0.01,0.07,0.1,0},{0,0,0,-1,0.05},      {0,0.01,0.07,0.1,0},{0,0,0.02,0,0} },
						{ {0,0,0.05,0,0},{0,0.1,-1,0.1,0}, {0.02,0.07,0,0.07,0.02}, {0,0.01,0,0.01,0},  {0,0,0,0,0}    }
};
int N, middle, ans;
int map[500][500];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N;
	middle = N / 2;
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < N; ++col) {
			cin >> map[row][col];
			ans += map[row][col];
		}
	}
	return;
}

void solve() {
	input();
	bfs();
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < N; ++col) {
			ans -= map[row][col];
		}
	}
	cout << ans;
	return;
}

void bfs() {
	int cnt = 0, dir = 0;
	int row = middle, col = middle;
	while (true) {
		cnt++;
		for (int x = 0; x < cnt; ++x) {
			row += dr[dir];
			col += dc[dir];
			if (col == -1) return;
			int data = map[row][col];
			map[row][col] = 0;
			int buf = 0, alpha_r = -1, alpha_c = -1;
			for (int r = 0; r < 5; ++r) {
				for (int c = 0; c < 5; ++c) {
					int nr = row - 2 + r;
					int nc = col - 2 + c;
					if (move_data[dir][r][c] == -1) {
						alpha_r = nr;
						alpha_c = nc;
					}
					else {
						buf += (int)(data * move_data[dir][r][c]);
						if (0 <= nr && nr < N && 0 <= nc && nc < N) {
							map[nr][nc] += (int)(data * move_data[dir][r][c]);
						}
					}
				}
			}
			if (0 <= alpha_r && alpha_r < N && 0 <= alpha_c && alpha_c < N) {
				map[alpha_r][alpha_c] += (data - buf);
			}
		}
		dir++;
		for (int x = 0; x < cnt; ++x) {
			row += dr[dir];
			col += dc[dir];
			int data = map[row][col];
			map[row][col] = 0;
			int buf = 0, alpha_r = -1, alpha_c = -1;
			for (int r = 0; r < 5; ++r) {
				for (int c = 0; c < 5; ++c) {
					int nr = row - 2 + r;
					int nc = col - 2 + c;
					if (move_data[dir][r][c] == -1) {
						alpha_r = nr;
						alpha_c = nc;
					}
					else {
						buf += (int)(data * move_data[dir][r][c]);
						if (0 <= nr && nr < N && 0 <= nc && nc < N) {
							map[nr][nc] += (int)(data * move_data[dir][r][c]);
						}
					}
				}
			}
			if (0 <= alpha_r && alpha_r < N && 0 <= alpha_c && alpha_c < N) {
				map[alpha_r][alpha_c] += (data - buf);
			}
		}
		dir++;
		dir %= 4;
	}
}


