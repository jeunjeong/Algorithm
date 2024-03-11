#include <iostream>
#include <queue>

#define EMPTY '.'
#define WALL '#'
#define HOLE 'O'

using namespace std;

void input();
void solve();
bool bfs();

int N, M, ans;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
char map[10][10];
queue<pair<pair<int, int>, pair<int, int>>> Q; // R, B

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N >> M;
	pair<int, int> R, B;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			cin >> map[r][c];
			if (map[r][c] == 'R') {
				R = { r,c };
				map[r][c] = EMPTY;
			}
			else if (map[r][c] == 'B') {
				B = { r,c };
				map[r][c] = EMPTY;
			}
		}
	}
	Q.push({ {R.first, R.second},{B.first, B.second} });
	return;
}

void solve() {
	input();
	if (bfs()) cout << ans;
	else cout << -1;
	return;
}

bool bfs() {
	while (!Q.empty() && ans < 10) { //10회 안에 통과하지 못하면 실패
		ans++;
		int size = Q.size();
		for (int siz = 0; siz < size; ++siz) {
			pair<pair<int, int>, pair<int, int>> pos = Q.front();
			Q.pop();
			for (int d = 0; d < 4; ++d) {
				int nr_R = pos.first.first;
				int nc_R = pos.first.second;
				int nr_B = pos.second.first;
				int nc_B = pos.second.second;
				bool flag_R = true, flag_B = true, blue_HOLE = true, red_HOLE = true;
								
				while (flag_B) {
					nr_B += dr[d];
					nc_B += dc[d];
					if (map[nr_B][nc_B] == WALL) {
						nr_B -= dr[d];
						nc_B -= dc[d];
						flag_B = false;
					}
					else if (map[nr_B][nc_B] == HOLE) {
						blue_HOLE = false;
						flag_B = false;
					}
				}
				while (flag_R) {
					nr_R += dr[d];
					nc_R += dc[d];
					if (map[nr_R][nc_R] == WALL) {
						nr_R -= dr[d];
						nc_R -= dc[d];
						flag_R = false;
					}
					else if (map[nr_R][nc_R] == HOLE) {
						red_HOLE = false;
						flag_R = false;
					}
				}

				if (d == 0) { //위쪽
					bool same = false;
					if (pos.first.first > pos.second.first) same = true;
					if (nc_R == nc_B && nr_R == nr_B) {  
						if (same) nr_R -= dr[d]; // 같은 위치이면 원래 빨간 구슬이 더 아래에 있었으므로 빨간구슬 한칸 아래로 이동
						else nr_B -= dr[d];
					}
				}
				else if (d == 1) { //아래쪽
					bool same = false;
					if (pos.first.first < pos.second.first) same = true;
					if (nc_R == nc_B && nr_R == nr_B) {
						if (same) nr_R -= dr[d]; 
						else nr_B -= dr[d];
					}
				}
				else if (d == 2) { //왼쪽
					bool same = false;
					if (pos.first.second > pos.second.second) same = true;
					if (nc_R == nc_B && nr_R == nr_B) {
						if (same) nc_R -= dc[d];
						else nc_B -= dc[d];
					}
				}
				else { //오른쪽
					bool same = false;
					if (pos.first.second < pos.second.second) same = true;					
					if (nc_R == nc_B && nr_R == nr_B) {
						if (same) nc_R -= dc[d];
						else nc_B -= dc[d];
					}
				}
				if (blue_HOLE && red_HOLE) {
					if (nr_R == pos.first.first && nc_R == pos.first.second && nr_B == pos.second.first && nc_B == pos.second.second) { //변화가 없으면 큐에 넣지않음 
						continue;
					}
					else {
						Q.push({ {nr_R, nc_R}, {nr_B, nc_B} }); // 둘 다 안빠지면 큐에 넣음
					}
				}
				else if (blue_HOLE && !red_HOLE) return true; // 빨간 공만 빠지면 성공 리턴
			}
		}
	}
	return false;
}