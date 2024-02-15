#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int TestCase, W, H, ans;
int dr[4] = { -1, 1, 0 , 0 };
int dc[4] = { 0, 0, -1, 1 };
char map[1000][1000];
bool visit_f[1000][1000];
bool visit_h[1000][1000];
queue<pair<int, int>> fire, human;

void input();
bool solve();


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> TestCase;
	for (int tc = 0; tc < TestCase; ++tc) {
		ans = 0;
		fire = queue<pair<int, int>>(); //testcase 마다 큐 초기화
		human = queue<pair<int, int>>(); //testcase 마다 큐 초기화
		memset(visit_f, false, sizeof(visit_f));
		memset(visit_h, false, sizeof(visit_h));
		input();
		if (solve()) {
			cout << ans << '\n';
		}
		else {
			cout << "IMPOSSIBLE" << '\n';
		}
	}
}

void input() {
	cin >> W >> H;
	for (int row = 0; row < H; ++row) {
		for (int col = 0; col < W; ++col) {
			cin >> map[row][col];
			if (map[row][col] == '@') {
				human.push({ row,col });
				map[row][col] = '.';
				visit_h[row][col] = true;
			}
			else if (map[row][col] == '*') {
				fire.push({ row,col });
				visit_f[row][col] = true;
			}
		}
	}
}

bool solve() {
	while (!fire.empty() || !human.empty()) {
		int fire_size = fire.size();
		int human_size = human.size();
		ans++;
		for (int roof = 0; roof < fire_size; ++roof) {
			pair<int, int> fire_pos = fire.front();
			fire.pop();
			int row = fire_pos.first;
			int col = fire_pos.second;
			for (int dir = 0; dir < 4; ++dir) {
				int nr = row + dr[dir];
				int nc = col + dc[dir];
				if (0 <= nr && nr < H && 0 <= nc && nc < W && map[nr][nc] == '.'&& !visit_f[nr][nc]) { //빈 공간이면 불이 옮겨붙음
					visit_f[nr][nc] = true;
					map[nr][nc] = '*';
					fire.push({ nr,nc });
				}
			}
		}
		for (int roof = 0; roof < human_size; ++roof) {
			pair<int, int> human_pos = human.front();
			human.pop();
			int row = human_pos.first;
			int col = human_pos.second;
			for (int dir = 0; dir < 4; ++dir) {
				int nr = row + dr[dir];
				int nc = col + dc[dir];
				if (0 <= nr && nr < H && 0 <= nc && nc < W && map[nr][nc] == '.' && !visit_h[nr][nc]) { //빈 공간이면 이동
					visit_h[nr][nc] = true;
					human.push({ nr,nc });
				}
				else if (nr < 0 || nr >= H || nc < 0 || nc >= W) { //탈출에 성공하면
					return true;
				}
			}
		}
	}
	return false;
}