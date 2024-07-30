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
		if ((row == N - 1) && (col == N - 1)) { // �����ϸ� ans ++
			ans++;
		}
		else { // ���� �ƴϸ� 
			next_check(pos);
		}
	}
	return;
}

void next_check(pair<int, pair<int, int>> pos) {
	int state = pos.first;
	int row = pos.second.first;
	int col = pos.second.second;
	if (state == 0) { // state == 0�� ��� ������, �밢�� �Ʒ� �̵� ����
		if ((col + 1) < N) {
			if (map[row][col + 1] == 0) {
				Q.push(make_pair(0, make_pair(row, col + 1))); //������ �̵�
			}
			if ((row + 1) < N && map[row + 1][col] == 0 && map[row + 1][col + 1] == 0 && map[row][col + 1] == 0) { // �밢�� �Ʒ� �̵�
				Q.push(make_pair(1, make_pair(row + 1, col + 1)));
			}
		}
	}
	else if (state == 1) { // state == 1�� ��� 3���� ��� �̵� ����
		if ((row + 1) < N) {
			if (map[row + 1][col] == 0) {
				Q.push(make_pair(2, make_pair(row + 1, col))); //�Ʒ� �̵�
			}
			if ((col + 1) < N && map[row + 1][col] == 0 && map[row + 1][col + 1] == 0 && map[row][col + 1] == 0) {
				Q.push(make_pair(1, make_pair(row + 1, col + 1))); //�밢�� �Ʒ� �̵�
			}
		}
		if ((col + 1) < N) { // ������ �̵�
			if (map[row][col + 1] == 0) {
				Q.push(make_pair(0, make_pair(row, col + 1)));
			}
		}
	}
	else if (state == 2) { // state == 2�� ��� �Ʒ�, �밢�� �Ʒ� �̵�����
		if ((row + 1) < N) {
			if (map[row + 1][col] == 0) {
				Q.push(make_pair(2, make_pair(row + 1, col))); //�Ʒ� �̵�
			}
			if ((col + 1) < N && map[row + 1][col] == 0 && map[row + 1][col + 1] == 0 && map[row][col + 1] == 0) {
				Q.push(make_pair(1, make_pair(row + 1, col + 1))); //�밢�� �Ʒ� �̵�
			}
		}
	}
	return;
}