#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

void input();
void solve();
void blizard(int d, int s);
bool bomb();
void change();
void shift();
void make_snail();

int N, middle, TC, ans;
int sr[5] = { 0, 0, 1, 0, -1 };
int sc[5] = { 0, -1, 0, 1, 0 };
int dr[5] = { 0, -1, 1, 0, 0 };
int dc[5] = { 0, 0, 0, -1, 1 };
int map[51][51];
bool visit[51][51];
vector<pair<int, int>> snail;
pair<int, int> blizard_info[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N >> TC;
	middle = N / 2;
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < N; ++col) {
			cin >> map[row][col];
		}
	}
	map[middle][middle] = -1;
	for (int idx = 0; idx < TC; ++idx) {
		cin >> blizard_info[idx].first >> blizard_info[idx].second;
	}
	return;
}

void solve() {
	input();
	make_snail();
	for (int idx = 0; idx < TC; ++idx) {
		blizard(blizard_info[idx].first, blizard_info[idx].second);
		shift();
		while (bomb()) shift();
		change();
	}
	cout << ans;
	return;
}

void blizard(int d, int s) {
	for (int distance = 1; distance <= s; ++distance) {
		int nr = middle + distance * dr[d];
		int nc = middle + distance * dc[d];
		map[nr][nc] = 0;
	}
	return;
}

bool bomb() {
	bool flag = false;
	int data = map[snail[0].first][snail[0].second];
	int start_idx = 0;
	int cnt = 0;
	for (int idx = 0; idx < snail.size(); ++idx) {
		int r = snail[idx].first;
		int c = snail[idx].second;
		if (map[r][c] != data) {
			if (cnt >= 4) {
				if (!flag) flag = true;
				ans += data * cnt;
				for (start_idx; start_idx < idx; ++start_idx) {
					map[snail[start_idx].first][snail[start_idx].second] = 0;
				}
			}
			start_idx = idx;
			cnt = 1;
			data = map[r][c];
		}
		else cnt++;
		if (map[r][c] == 0) break;
	}
	return flag;
}

void change() {
	int data = map[snail[0].first][snail[0].second];
	int cnt = 0;
	queue<int> after_change;
	for (int idx = 0; idx < snail.size(); ++idx) {
		int r = snail[idx].first;
		int c = snail[idx].second;
		if (map[r][c] == 0) {
			break;
		}
		else if (map[r][c] != data) {
			after_change.push(cnt);
			after_change.push(data);
			data = map[r][c];
			cnt = 1;
		}
		else {
			cnt++;
		}

	}
	after_change.push(cnt);
	after_change.push(data);
	int i = 0;
	while (i < snail.size()) {
		if (after_change.empty()) {
			map[snail[i].first][snail[i].second] = 0;
		}
		else {
			map[snail[i].first][snail[i].second] = after_change.front();
			after_change.pop();
		}
		i++;

	}
	return;
}

void shift() {
	queue<pair<int, int>> empty_pos;
	for (int idx = 0; idx < snail.size(); ++idx) {
		int r = snail[idx].first;
		int c = snail[idx].second;
		if (map[r][c] == 0) {
			empty_pos.push({ r,c });
		}
		else {
			if (!empty_pos.empty()) {
				pair<int, int> n_pos = empty_pos.front();
				empty_pos.pop();
				map[n_pos.first][n_pos.second] = map[r][c];
				empty_pos.push({ r,c });
				map[r][c] = 0;
			}
		}
	}
	return;
}

void make_snail() {
	int cnt = 1;
	int dir = 1;
	int row = middle;
	int col = middle;
	while (true) {
		for (int rep = 0; rep < cnt; ++rep) {
			row += sr[dir];
			col += sc[dir];
			if (col == -1) return;
			snail.push_back({ row,col });
		}
		dir++;
		for (int rep = 0; rep < cnt; ++rep) {
			row += sr[dir];
			col += sc[dir];
			snail.push_back({ row,col });
		}
		dir++;
		dir = dir == 5 ? 1 : dir;
		cnt++;
	}
}