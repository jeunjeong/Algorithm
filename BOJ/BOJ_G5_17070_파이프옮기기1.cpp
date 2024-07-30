#include <iostream>
#include <queue>

using namespace std;

void input();
void solve();
void bfs();
void next_check(pair<int, pair<int, int>>);

int N, ans = 0;
int map[16][16];
queue<pair<int, pair<int, int>>> Q; // (state, (r , c))

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cin >> map[r][c];
		}
	}
	return;
}

void solve() {
	input();
	Q.push(make_pair(0, make_pair(0, 1)));
	bfs();
	cout << ans;
	return;
}

void bfs() {
	while (!Q.empty()) {
		pair<int, pair<int, int>> pos = Q.front();
		Q.pop();
		int state = pos.first;
		int row = pos.second.first;
		int col = pos.second.second;
		if ((row == N - 1) && (col == N - 1)) { // 도착하면 ans ++
			ans++;
		}
		else { // 도착 아니면 
			next_check(pos);
		}
	}
	return;
}

void next_check(pair<int, pair<int, int>> pos) {
	int state = pos.first;
	int row = pos.second.first;
	int col = pos.second.second;
	if (state == 0) { // state == 0인 경우 오른쪽, 대각선 아래 이동 가능
		if ((col + 1) < N) {
			if (map[row][col + 1] == 0) {
				Q.push(make_pair(0, make_pair(row, col + 1))); //오른쪽 이동
			}
			if ((row + 1) < N && map[row + 1][col] == 0 && map[row + 1][col + 1] == 0 && map[row][col + 1] == 0) { // 대각선 아래 이동
				Q.push(make_pair(1, make_pair(row + 1, col + 1)));
			}
		}
	}
	else if (state == 1) { // state == 1인 경우 3방향 모두 이동 가능
		if ((row + 1) < N) {
			if (map[row + 1][col] == 0) {
				Q.push(make_pair(2, make_pair(row + 1, col))); //아래 이동
			}
			if ((col + 1) < N && map[row + 1][col] == 0 && map[row + 1][col + 1] == 0 && map[row][col + 1] == 0) {
				Q.push(make_pair(1, make_pair(row + 1, col + 1))); //대각선 아래 이동
			}
		}
		if ((col + 1) < N) { // 오른쪽 이동
			if (map[row][col + 1] == 0) {
				Q.push(make_pair(0, make_pair(row, col + 1)));
			}
		}
	}
	else if (state == 2) { // state == 2인 경우 아래, 대각선 아래 이동가능
		if ((row + 1) < N) {
			if (map[row + 1][col] == 0) {
				Q.push(make_pair(2, make_pair(row + 1, col))); //아래 이동
			}
			if ((col + 1) < N && map[row + 1][col] == 0 && map[row + 1][col + 1] == 0 && map[row][col + 1] == 0) {
				Q.push(make_pair(1, make_pair(row + 1, col + 1))); //대각선 아래 이동
			}
		}
	}
	return;
}