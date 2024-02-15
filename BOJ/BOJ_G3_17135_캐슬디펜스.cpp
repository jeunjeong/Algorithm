#include <iostream>
#include <set>
#include <queue>
using namespace std;

void input();
void solve();
void combination(int depth, int next);
void deepcopy();
void attack();
void move();

int N, M, D, ans = 0, cnt = 0;
int cArr[3];
int copy_map[15][15];
int map[15][15];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	combination(0, 0);
	cout << ans;
	return 0;
}

void input() {
	cin >> N >> M >> D;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			cin >> copy_map[r][c];
		}
	}
}

void solve() {
	bool flag = true;
	for (int r = 0; r < N; ++r) {
		attack();
		move();
	}
}
// 1. M열 중 궁수를 배치할 3칸 선택
void combination(int depth, int start) {
	if (depth == 3) {
		// 2. 여러 경우의 수를 탐색해야하므로 맵 복사
		deepcopy();
		solve();
		// 5. 정답 갱신
		ans = cnt > ans ? cnt : ans;
		cnt = 0;
		return;
	}

	for (int i = start; i <= M; i++) {
		cArr[depth] = i;
		combination(depth + 1, i + 1);
	}
}

void deepcopy() {
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			map[r][c] = copy_map[r][c];
		}
	}
}

// 3. 공격 - bfs로 거리가 D 내에 있는 가장 왼쪽에 있는 적 탐색
void attack() {
	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;
	queue<pair<int, int>> Q3;
	bool visit1[15][15] = { false, };
	bool visit2[15][15] = { false, };
	bool visit3[15][15] = { false, };
	set<pair<int, int>> set;
	int dr[4] = { 0,-1, 0 };
	int dc[4] = { -1,0, 1 };
	int depth = 0;
	Q1.push({ N, cArr[0] });
	Q2.push({ N, cArr[1] });
	Q3.push({ N, cArr[2] });
	while (depth < D && !Q1.empty()) {
		depth++;
		int size = Q1.size();
		for (int s = 0; s < size; ++s) {
			pair<int, int> pos = Q1.front();
			Q1.pop();
			for (int d = 0; d < 3; ++d) {
				int nr = pos.first + dr[d];
				int nc = pos.second + dc[d];
				if (0 <= nr && nr < N && 0 <= nc && nc < M && !visit1[nr][nc]) {
					if (map[nr][nc] == 1) {
						set.insert({ nr,nc });
						d = 4;
						s = size;
						depth = D;
					}
					visit1[nr][nc] = true;
					Q1.push({ nr,nc });
				}
			}
		}
	}
	depth = 0;
	while (depth < D && !Q2.empty()) {
		depth++;
		int size = Q2.size();
		for (int s = 0; s < size; ++s) {
			pair<int, int> pos = Q2.front();
			Q2.pop();
			for (int d = 0; d < 3; ++d) {
				int nr = pos.first + dr[d];
				int nc = pos.second + dc[d];
				if (0 <= nr && nr < N && 0 <= nc && nc < M && !visit2[nr][nc]) {
					if (map[nr][nc] == 1) {
						set.insert({ nr,nc });
						d = 4;
						s = size;
						depth = D;
					}
					visit2[nr][nc] = true;
					Q2.push({ nr,nc });
				}
			}
		}
	}
	depth = 0;
	while (depth < D && !Q3.empty()) {
		depth++;
		int size = Q3.size();
		for (int s = 0; s < size; ++s) {
			pair<int, int> pos = Q3.front();
			Q3.pop();
			for (int d = 0; d < 3; ++d) {
				int nr = pos.first + dr[d];
				int nc = pos.second + dc[d];
				if (0 <= nr && nr < N && 0 <= nc && nc < M && !visit3[nr][nc]) {
					if (map[nr][nc] == 1) {
						set.insert({ nr,nc });
						d = 4;
						s = size;
						depth = D;
					}
					visit3[nr][nc] = true;
					Q3.push({ nr,nc });
				}
			}
		}
	}
	for (auto i : set) {
		cnt++;
		map[i.first][i.second] = 0;
	}
}

// 4. 적 이동 - 한 칸씩 밑으로 
void move() {
	for (int r = N - 1; r >= 0; --r) {
		for (int c = 0; c < M; ++c) {
			if (map[r][c] == 1) {
				map[r][c] = 0;
				if (r + 1 < N) {
					map[r + 1][c] = 1;
				}
			}
		}
	}
}