#include <iostream>

#define MAXR 10000
#define MAXC 500

using namespace std;

void input();
void solve();
void dfs(int depth, int row, int col);

char map[MAXR][MAXC];
bool visited[MAXR][MAXC] = { false, };
int dr[3] = { -1,0,1 };
int dc[3] = { 1,1,1 };
int R, C, res = 0;
bool flag = true;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	return 0;
}
void input() {
	cin >> R >> C;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			cin >> map[r][c];
		}
	}
}

void solve() {
	for (int r = 0; r < R; ++r) {
		flag = true;
		dfs(1, r, 0);
	}
	cout << res;
}

void dfs(int depth, int row, int col) {
	visited[row][col] = true;
	if (depth == C) {
		res += 1; // count +1
		flag = false;
		return;
	}

	for (int vec = 0; vec < 3; ++vec) {
		int nr = row + dr[vec];
		int nc = col + dc[vec];
		if (0 <= nr && nr < R && 0 <= nc && nc < C && map[nr][nc] == '.' && !visited[nr][nc]) { //범위안에 있고 비어있으면(파이프라인 세울 수 있으면)
			dfs(depth + 1, nr, nc);
			if (!flag) return;
		}
	}
}

