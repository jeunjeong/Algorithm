#include <iostream>
#include <vector>

using namespace std;

void input();
void solve();
void set_student();
void check_score();

int N, N_student, ans;
int dr[4] = { -1, 0, 0, 1 };
int dc[4] = { 0, -1, 1, 0 };
int table[20][20];
int student[401][4];
vector<int> st_order;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N;
	N_student = N * N;
	for (int i = 0; i < N_student; ++i) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		st_order.push_back(a);
		student[a][0] = b;
		student[a][1] = c;
		student[a][2] = d;
		student[a][3] = e;
	}
	return;
}

void solve() {
	input();
	set_student();
	check_score();
	
	cout << ans;
	return;
}

void set_student() {
	table[1][1] = st_order[0];
	for (int i = 1; i < st_order.size(); ++i) {
		int set_st = st_order[i];
		//cout << set_st << '\n';
		int row = 0, col = 0, empty = -1, like = -1;
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				if (table[r][c] == 0) {
					int n_empty = 0;
					int n_like = 0;
					for (int d = 0; d < 4; ++d) {
						int nr = r + dr[d];
						int nc = c + dc[d];
						if (0 <= nr && nr < N && 0 <= nc && nc < N) {
							if (table[nr][nc] == 0) {
								n_empty++;
							}
							else {
								for (int j = 0; j < 4; ++j) {
									if (table[nr][nc] == student[set_st][j]) { // 좋아하는 목록에 있으면
										n_like++;
									}
								}
							}
						}
					}
					//cout << r << " : " << c << " -> " << like << " " << n_like << empty << " " << n_empty << '\n';
					if (like < n_like) {
						row = r;
						col = c;
						like = n_like;
						empty = n_empty;
					}
					else if (like == n_like && empty < n_empty) {
						row = r;
						col = c;
						empty = n_empty;
					}
				}
			}
		}
		table[row][col] = set_st;
		//cout << set_st << " -> " << row << " : " << col << '\n';
	}
	return;
}

void check_score() {
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			int student_num = table[r][c];
			int score = 0;
			for (int d = 0; d < 4; ++d) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if (0 <= nr && nr < N && 0 <= nc && nc < N) {
					for (int i = 0; i < 4; ++i) {
						if (student[student_num][i] == table[nr][nc]) {
							score++;
						}
					}
				}
			}
			if (score == 2) {
				score = 10;
			}
			else if (score == 3) {
				score = 100;
			}
			else if (score == 4) {
				score = 1000;
			}
			ans += score;
		}
	}
	return;
}