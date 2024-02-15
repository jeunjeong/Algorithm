#include <iostream>
#include <vector>

using namespace std;

int R, C, ans = 0;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
char matrix[21][21];

void input();
void solve();
void dfs(bool alphabet[], int row, int col, int depth);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}

void input() {
	cin >> R >> C;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cin >> matrix[r][c];
		}
	}
}

void solve() {
	bool alphabet[28] = { false, };
	dfs(alphabet, 0, 0, 1);
	cout << ans;
}

void dfs(bool alphabet[], int row, int col, int depth) {
	int num = matrix[row][col] - 'A';
	alphabet[num] = true;
	for (int dir = 0; dir < 4; ++dir) {
		int nr = row + dr[dir];
		int nc = col + dc[dir];
		if (0 <= nr && nr < R && 0 <= nc && nc < C && !alphabet[(matrix[nr][nc] - 'A')]) {
			dfs(alphabet, nr, nc, depth + 1);
			alphabet[(matrix[nr][nc] - 'A')] = false;
		}
		else {
			ans = (ans > depth ? ans : depth);
		}
	}
}