#include <iostream>
#include <vector>
using namespace std;

void input();
void solve();
void combination(int cnt, int idx);

bool ans = false;
int N, n_emp = 0, n_tea = 0;
int Arr[3] = { 0, };
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
char map[6][6];
vector<pair<int, int>> emp;
vector<pair<int, int>> teacher;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	combination(0,0);
	if (!ans) cout << "NO";
	return 0;
}

void input() {
	cin >> N;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cin >> map[r][c];
			if (map[r][c] == 'X') {
				n_emp++;
				emp.push_back({ r,c });
			}
			else if (map[r][c] == 'T') {
				n_tea++;
				teacher.push_back({ r,c });
			}
		}
	}
}

void solve() {
	for (int teach = 0; teach < n_tea; ++teach) {
		pair<int, int> pos = teacher[teach];
		for (int d = 0; d < 4; ++d) {
			int nr = pos.first + dr[d];
			int nc = pos.second + dc[d];
			bool flag = true;
			while (flag) {
				if (0 <= nr && nr < N && 0 <= nc && nc < N) {
					if (map[nr][nc] == 'T') {
						flag = false;
					}
					else if (map[nr][nc] == 'X') {
						nr += dr[d];
						nc += dc[d];
					}
					else if (map[nr][nc] == 'O') {
						flag = false;
					}
					else { // 학생이보이면 실패
						return;
					}
				}
				else flag = false;
			}
		}
	}
	ans = true;
	cout << "YES";
}

void combination(int cnt, int start) {
	if (!ans) {
		if (cnt == 3) {
			for (int i = 0; i < 3; ++i) {
				pair<int, int> pos = emp[Arr[i]];
				map[pos.first][pos.second] = 'O';
			}
			solve();
			for (int i = 0; i < 3; ++i) {
				pair<int, int> pos = emp[Arr[i]];
				map[pos.first][pos.second] = 'X';
			}
			return;
		}
		for (int i = start; i < n_emp; i++) {
			Arr[cnt] = i;
			combination(cnt + 1, i + 1);
		}
	}
}