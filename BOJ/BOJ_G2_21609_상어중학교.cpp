#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void input();
void solve();
bool bfs();
void gravity();
void turn();

int ans, N, M, cnt;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int block[20][20];
bool visit[20][20];
bool group[20][20];
bool max_group[20][20];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N >> M;
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < N; ++col) {
			cin >> block[row][col];
		}
	}
	return;
}

void solve() {
	input();
	bool flag = true;
	while (flag) {
		flag = bfs();
		gravity();
		turn();
		gravity();
	}
	cout << ans;
	return;
}

bool bfs() {
	int max_cnt = 0;
	int max_rainbow = 0;
	memset(visit, false, sizeof(group));
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < N; ++col) {
			if (block[row][col] > 0 && !visit[row][col]) {
				memset(group, false, sizeof(group));
				queue<pair<int, int>> Q;
				Q.push({ row,col });
				visit[row][col] = true;
				group[row][col] = true;
				int cnt = 1;
				int rainbow_cnt = 0;
				while (!Q.empty()) {
					pair<int, int> pos = Q.front();
					Q.pop();
					for (int d = 0; d < 4; ++d) {
						int nr = pos.first + dr[d];
						int nc = pos.second + dc[d];
						if (0 <= nr && nr < N && 0 <= nc && nc < N && group[nr][nc] == false && (block[nr][nc] == 0 || block[nr][nc] == block[row][col])) {
							group[nr][nc] = true;
							if (block[nr][nc] == 0) { // 무지개블록이면 블록 카운트에는 센다
								Q.push({ nr,nc });
								rainbow_cnt++;
							}
							else if (block[nr][nc] == block[row][col]) { // 같은 색 블록이면 방문체크도 한다
								visit[nr][nc] = true;
								Q.push({ nr,nc });
								cnt++;
							}
						}
					}
				}
				if (cnt + rainbow_cnt > max_cnt + max_rainbow || ((cnt+rainbow_cnt == max_cnt+max_rainbow) && rainbow_cnt >= max_rainbow)) { // 가장 큰 블록이면 big_group에 영역 저장
					memset(max_group, false, sizeof(max_group));
					for (int row = 0; row < N; ++row) {
						for (int col = 0; col < N; ++col) {
							if (group[row][col]) {
								max_group[row][col] = true;
							}
						}
					}
					max_cnt = cnt;
					max_rainbow = rainbow_cnt;
				}
			}
		}
	}
	max_cnt = max_cnt + max_rainbow;
	if (max_cnt > 1) {
		ans += max_cnt * max_cnt;
		for (int row = 0; row < N; ++row) {
			for (int col = 0; col < N; ++col) {
				if (max_group[row][col]) {
					block[row][col] = -2;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}

void gravity() {
	for (int row = N - 1; row >= 0; --row) {
		for (int col = 0; col <= N - 1; ++col) {
			if (block[row][col] >= 0) {
				int nr = row + 1;
				while (nr <= N - 1 && block[nr][col] == -2) nr++;
				nr--;
				if (nr != row) {
					block[nr][col] = block[row][col];
					block[row][col] = -2;
				}
			}
		}
	}
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < N; ++col) {
		}
	}
	return;
}

void turn() {
	int buf[20][20] = { 0, };
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < N; ++col) {
			buf[N - 1 - col][row] = block[row][col];
		}
	}
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < N; ++col) {
			block[row][col] = buf[row][col];
		}
	}
	return;
}