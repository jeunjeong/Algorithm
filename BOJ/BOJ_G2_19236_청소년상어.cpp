#include <iostream>
#include <vector>
#include <cstring>
#define SIZE 4
using namespace std;

struct FISH {
	int row;
	int col;
	int dir;
};

void input();
void solve();
void fish_move(FISH new_fish[17], int new_map[SIZE][SIZE]);
void shark_move(FISH shark, FISH fish[17], int map[SIZE][SIZE], int cnt);
void copy_map(int map[SIZE][SIZE], int new_map[SIZE][SIZE]);
void copy_fish(FISH fish[17], FISH new_fish[17]);


int ans = 0;
int dr[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int first_map[SIZE][SIZE];

FISH first_shark;
FISH first_fish[17];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	int num, dir;
	for (int row = 0; row < SIZE; ++row) {
		for (int col = 0; col < SIZE; ++col) {
			cin >> num >> dir;
			first_fish[num] = { row, col, dir };
			first_map[row][col] = num;
		}
	}
	return;
}

void solve() {
	input();
	int eat = first_map[0][0];
	first_shark = { 0, 0, first_fish[eat].dir }; // 상어의 초기위치는 (0,0), 방향은 0,0에 있던 물고기의 방향
	ans += eat;
	first_fish[eat].dir = -1;
	first_map[0][0] = -1;
	fish_move(first_fish, first_map);
	shark_move(first_shark, first_fish, first_map, ans);
	cout << ans;
	return;
}

void fish_move(FISH new_fish[17], int new_map[SIZE][SIZE]) {
	for (int idx = 1; idx < 17; ++idx) {
		int row = new_fish[idx].row;
		int col = new_fish[idx].col;
		int dir = new_fish[idx].dir;
		if (dir == -1) continue; // 먹혔으면 비교할 필요가 없으므로 넘어감
		else {
			int cnt = 0;
			bool flag = true;
			while (flag) {
				int nr = row + dr[dir];
				int nc = col + dc[dir];
				if (0 <= nr && nr < SIZE && 0 <= nc && nc < SIZE && new_map[nr][nc] > -1) { // 다음 위치가 범위 내에 있고, 상어가 있는곳이 아니면 물고기 이동
					flag = false;
					int buf_fish = new_map[nr][nc];
					int buf_fish_dir = new_fish[buf_fish].dir;
					new_fish[idx] = { nr,nc, dir };
					new_map[nr][nc] = idx;
					new_fish[buf_fish] = { row, col, buf_fish_dir };
					new_map[row][col] = buf_fish;
				}
				dir++;
				cnt++;
				dir = dir > 8 ? dir - 8 : dir;
				if (cnt == 9) { // 한바퀴 다 돌아도 갈 수 있는 곳이 없으면 정지
					flag = false;
				}
			}
		}
	}
	return;
}

void shark_move(FISH shark, FISH fish[17], int map[SIZE][SIZE], int cnt) {
	bool flag = false; // 종료조건 flag
	int move_size = 1;
	while (move_size <= 3) { // 4 * 4 map이므로 최대 3칸 이동가능
		int s_row = shark.row;
		int s_col = shark.col;
		int s_dir = shark.dir;
		int nr = s_row + move_size * dr[s_dir];
		int nc = s_col + move_size * dc[s_dir];
		if (0 <= nr && nr < SIZE && 0 <= nc && nc < SIZE && map[nr][nc] != 0) { // 범위안에 있고 물고기가 있으면 먹으러 감
			int new_map[SIZE][SIZE];
			copy_map(map, new_map);
			FISH new_fish[17];
			copy_fish(fish, new_fish);
			FISH new_shark;
			int eat = map[nr][nc];
			int new_cnt = cnt + eat; // 상어가 물고기를 잡아먹음
			new_shark = { nr, nc, new_fish[eat].dir }; // 물고기를 잡아먹고 물고기가 있던 곳으로 이동
			new_fish[eat].dir = -1; // 먹힌 물고기의 방향은 -1(죽었음)
			new_map[s_row][s_col] = 0;
			new_map[nr][nc] = -1;// 상어 이동
			fish_move(new_fish, new_map);
			shark_move(new_shark, new_fish, new_map, new_cnt);
			flag = true;
		}
		move_size++;
	}
	if (!flag) { // 상어가 한번도 이동하지 못한 경우 종료조건이므로 ans 갱신
		ans = ans < cnt ? cnt : ans;
	}
	return;
}

void copy_map(int map[SIZE][SIZE], int new_map[SIZE][SIZE]) {
	for (int row = 0; row < SIZE; ++row) {
		for (int col = 0; col < SIZE; ++col) {
			new_map[row][col] = map[row][col];
		}
	}
	return;
}

void copy_fish(FISH fish[17], FISH new_fish[17]) {
	for (int idx = 0; idx < 17; ++idx) {
		new_fish[idx] = fish[idx];
	}
	return;
}
