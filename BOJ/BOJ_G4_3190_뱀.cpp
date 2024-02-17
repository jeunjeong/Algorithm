#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void input();
void solve();
int N, K, L, dir = 2, ans = 0;
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };
int map[100][100];
bool apple[100][100] = { false, };
queue<pair<int, char>> turn;
queue<pair<int, int>> snake;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	cout << ans;
	return 0;
}

void input() {
	cin >> N;
	cin >> K;
	for (int k = 0; k < K; ++k) {
		int row, col;
		cin >> row >> col;
		apple[row - 1][col - 1] = true;
	}
	cin >> L;
	for (int d = 0; d < L; ++d) {
		int t;
		char c;
		cin >> t >> c;
		turn.push({ t,c });
	}
}

void solve() {
	snake.push({ 0,0 });
	map[0][0] = 1;
	pair<int, char> t_time = turn.front();
	turn.pop();
	bool flag = true;
	while (flag) {
		ans++;
		int nr = snake.back().first + dr[dir];
		int nc = snake.back().second + dc[dir];
		if (0 <= nr && nr < N && 0 <= nc && nc < N && map[nr][nc] == 0) {
			if (apple[nr][nc]) { // 다음 위치에 사과가 있으면
				snake.push({ nr,nc });
				map[nr][nc] = 1; // 몸 길이도 늘어남
				apple[nr][nc] = false;
			}
			else { // 사과가 없으면
				snake.push({ nr,nc });
				pair<int,int> pos = snake.front();
				snake.pop();
				map[pos.first][pos.second] = 0; //꼬리도 전진
				map[nr][nc] = 1; //머리는 전진
			}
		}
		else {
			flag = false;
			return;
		}
		if (ans == t_time.first) {
			if (t_time.second == 'D') {
				dir = (dir + 1) % 4;
			}
			else {
				dir = dir == 0 ? 3 : dir - 1;
			}
			if (!turn.empty()) {
				t_time = turn.front();
				turn.pop();
			}
		}
	}
}