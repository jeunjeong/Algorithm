#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();
int bfs();

struct position {
	int r, c, dep;
};

int N, M, K, T = 1;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int map[1000][1000];
bool visit[1000][1000][10];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N >> M >> K;
	for (int r = 0; r < N; ++r) {
		string str;
		cin >> str;
		for (int c = 0; c < M; ++c) {
			map[r][c] = str[c] - '0';
		}
	}
}

void solve() {
	input();
	cout << bfs();
}

int bfs() {
	queue<position> Q;
	Q.push({ 0,0,0 });
	visit[0][0][0] = true;
	while (!Q.empty()) {
		T++;
		int siz = Q.size();
		for (int s = 0; s < siz; ++s) {
			position pos = Q.front();
			if (pos.r == N - 1 && pos.c == M - 1) {
				return T - 1;
			}
			Q.pop();
			if (T % 2 == 1) { //밤인 경우
				Q.push(pos); // 정지할 수 있음;
				for (int d = 0; d < 4; ++d) {
					int nr = pos.r + dr[d];
					int nc = pos.c + dc[d];
					if (0 <= nr && nr < N && 0 <= nc && nc < M && map[nr][nc] == 0 && !visit[nr][nc][pos.dep]) { // 밤에는 벽을 부술 수 없음
						Q.push({ nr,nc,pos.dep });
						visit[nr][nc][pos.dep] = true;
					}
				}
			}
			else { //낮인 경우
				for (int d = 0; d < 4; ++d) {
					int nr = pos.r + dr[d];
					int nc = pos.c + dc[d];
					if (0 <= nr && nr < N && 0 <= nc && nc < M) {
						if (map[nr][nc] == 0 && !visit[nr][nc][pos.dep]) {
							Q.push({ nr,nc,pos.dep });
							visit[nr][nc][pos.dep] = true;
						}
						else if (map[nr][nc] == 1 && pos.dep < K && !visit[nr][nc][pos.dep + 1]) {
							Q.push({ nr,nc,pos.dep + 1 });
							visit[nr][nc][pos.dep + 1] = true;
						}
					}
				}
			}
		}
	}
	return -1;
}