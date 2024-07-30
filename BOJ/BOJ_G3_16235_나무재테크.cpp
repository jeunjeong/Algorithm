#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void input();
void solve();
void spring_summer();
void fall();
void winter();

int N, M, K, ans;
int dr[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int A_arr[11][11];
int map[11][11];
vector<int> trees[11][11];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N >> M >> K;
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			cin >> A_arr[r][c];
			map[r][c] = 5;
		}
	}
	int r, c, a;
	for (int i = 0; i < M; ++i) {
		cin >> r >> c >> a; // 나무의 위치 (r, c), 나무의 나이 a
		trees[r][c].push_back(a);
	}
	return;
}

void solve() {
	input();
	for (int year = 0; year < K; ++year) {
		spring_summer();
		fall();
		winter();
	}
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			ans += trees[r][c].size();
		}
	}
	cout << ans;
	return;
}

void spring_summer() {
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			int flag = -1;
			for (int i = trees[r][c].size() - 1; i >= 0; --i) {
				if (flag == -1 && trees[r][c][i] <= map[r][c]) { // 나이가 양분보다 작거나 같으면 나이를 먹음
					map[r][c] -= trees[r][c][i];
					trees[r][c][i] = trees[r][c][i] + 1;
				}
				else { 
					if(flag == -1) flag = i;
					map[r][c] += trees[r][c][i] / 2;
					trees[r][c][i] = 0;
				}
			}
			if (flag != -1) trees[r][c].erase(trees[r][c].begin(), trees[r][c].begin() + flag + 1);
		}
	}
	return;
}

void fall() {
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			for (int i = trees[r][c].size() - 1; i >= 0; --i) {
				if (trees[r][c][i] % 5 == 0) { // 5의 배수이면 번식
					for (int d = 0; d < 8; ++d) {
						int nr = r + dr[d];
						int nc = c + dc[d];
						if (0 < nr && nr <= N && 0 < nc && nc <= N) {// 범위 안에 있으면 번식
							trees[nr][nc].push_back(1);
						}
					}
				}
			}
		}
	}
	return;
}

void winter() {
	for (int r = 1; r <= N; ++r) {
		for (int c = 1; c <= N; ++c) {
			map[r][c] += A_arr[r][c];
		}
	}
	return;
}