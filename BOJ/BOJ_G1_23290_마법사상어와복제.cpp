#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void input();
void solve();
void copy();
void move_fish();
void move_shark();
void dfs(int depth, int eat, pair<int, int> pos[3], int row, int col);
void delete_smell();
void paste();

int M, S, ans, max_eat;
int fr[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 }; // 물고기 이동 방향 idx 1 ~ 8 왼쪽부터 시계방향
int fc[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int sr[5] = { 0, -1, 0, 1, 0 }; // 상어 이동 방향 사전순 
int sc[5] = { 0, 0, -1, 0, 1 };
int smell[4][4];
pair<int, int> shark;
pair<int, int> max_pos[3];
queue<int> map[4][4];
queue<int> buf[4][4];
bool visit[4][4];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> M >> S;
	for (int fish = 0; fish < M; ++fish) {
		int r, c, d;
		cin >> r >> c >> d;
		map[r - 1][c - 1].push(d);
	}
	int r, c;
	cin >> r >> c;
	shark.first = r - 1;
	shark.second = c - 1;
	return;
}

void solve() {
	input();
	for (int practice = 0; practice < S; ++practice) {
		copy(); // 1번 복제마법 시전
		move_fish(); // 2번 물고기 이동
		move_shark(); // 3번 상어 이동
		delete_smell(); //4번 2번 전 물고기냄새 삭제
		paste(); // 1번 복제마법 완료
	}
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			ans += map[row][col].size();
		}
	}
	cout << ans;
	return;
}

void copy() {
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			buf[row][col] = queue<int>();
			if (!map[row][col].empty()) { // 물고기가 있는 칸이면
				int siz = map[row][col].size();
				for (int s = 0; s < siz; ++s) {
					int data = map[row][col].front();
					map[row][col].pop();
					buf[row][col].push(data);
					map[row][col].push(data);
				}
			}
		}
	}
	return;
}

void move_fish() {
	queue<int> buf_fish[4][4];
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			if (map[row][col].empty()) continue; // 빈칸이면 pass 
			else { // 물고기가 있는 칸이면 움직임
				int siz = map[row][col].size();
				for (int s = 0; s < siz; ++s) {
					int fish_dir = map[row][col].front();
					for (int d = 8; d > 0; --d) {
						int nd = (d + fish_dir) > 8 ? d + fish_dir - 8 : d + fish_dir;
						//cout << row << " : " << col << " : " << fish_dir << " : " << nd << '\n';
						int nr = row + fr[nd];
						int nc = col + fc[nd];
						if (0 <= nr && nr < 4 && 0 <= nc && nc < 4 && (shark.first != nr || shark.second != nc) && smell[nr][nc] == 0) { // 범위안에 있고, 상어 위치가 아니고 물고기 냄새가 없는 칸  
							map[row][col].pop(); 
							buf_fish[nr][nc].push(nd);// 갈 수 있는 곳을 찾으면 물고기 이동
							d = -1;
						}
					}
				}
			}
		}
	}
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			while (!buf_fish[row][col].empty()) {
				int data = buf_fish[row][col].front();
				buf_fish[row][col].pop();
				map[row][col].push(data);
			}
		}
	}
	return;
}

void move_shark() {
	memset(visit, false, sizeof(visit));
	max_eat = -1;
	pair<int, int> pos[3];
	dfs(0, 0, pos, shark.first, shark.second);
	for (int s = 0; s < 3; ++s) {
		int r = max_pos[s].first, c = max_pos[s].second;
		if (map[r][c].empty()) continue; // 빈 칸이면 pass
		else { // 물고기가 있던 칸이면 queue를 초기화하고(물고기 다 잡아먹고) 물고기 냄새를 남김
			map[r][c] = queue<int>();
			smell[r][c] = 3;
		}
	}
	shark = { max_pos[2].first, max_pos[2].second };
	return;
}

void dfs(int depth, int eat, pair<int, int> pos[3], int row, int col) {
	if (depth == 3) {
		if (eat > max_eat) {
			max_eat = eat;
			max_pos[0] = pos[0];
			max_pos[1] = pos[1];
			max_pos[2] = pos[2];
		}
		return;
	}
	else {
		for (int d = 1; d <= 4; ++d) {
			int nr = row + sr[d];
			int nc = col + sc[d];
			if (0 <= nr && nr < 4 && 0 <= nc && nc < 4) {
				pos[depth] = { nr, nc };
				if (visit[nr][nc]) { // 방문했던곳이면
					dfs(depth + 1, eat, pos, nr, nc);
				}
				else if (!visit[nr][nc] && !map[nr][nc].empty()) {
					visit[nr][nc] = true;
					dfs(depth + 1, eat + map[nr][nc].size(), pos, nr, nc);
					visit[nr][nc] = false;
				}
				else {
					dfs(depth + 1, eat, pos, nr, nc);
				}
			}
		}
	}
}

void delete_smell() {
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			if (smell[row][col] > 0) { // 1번 전 냄새이면 
				smell[row][col]--;
			}
		}
	}
	return;
}

void paste() {
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			while (!buf[row][col].empty()) {
				int data = buf[row][col].front();
				buf[row][col].pop();
				map[row][col].push(data);
			}
		}
	}
	return;
}
