#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

void input();
void solve();
void section(); //섬의 모서리 확인하는 함수
void brid_len(int a, int b);

int N, ans= 10000, sec;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int map[100][100];
bool cArr[5000];
bool visit[100][100];
vector<pair<int, int>> island[5000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
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
}

void solve() {
	section();
	for (int i = 0; i < sec-1; ++i) {
		for (int j = i + 1; j < sec; ++j) {
			brid_len(i, j);
		}
	}
	cout << ans - 1;
	return;
}

void section() {
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			if (map[r][c] == 1) {
				memset(visit, false, sizeof(visit));
				queue<pair<int, int>> Q;
				Q.push({ r,c });
				visit[r][c] = true;
				while (!Q.empty()) {
					pair<int, int> pos = Q.front();
					Q.pop();
					map[pos.first][pos.second] = 0;
					bool flag = true;
					for (int d = 0; d < 4; ++d) {
						int nr = pos.first + dr[d];
						int nc = pos.second + dc[d];
						if (0 <= nr && nr < N && 0 <= nc && nc < N && !visit[nr][nc]) { // 모서리가 아님
							if (flag && map[nr][nc] == 0) {
								island[sec].push_back({ pos.first, pos.second });
								flag = false;
								//cout << sec << "   " << pos.first << " : " << pos.second << '\n';
							}
							else if(map[nr][nc] == 1){
								Q.push({ nr,nc });
								visit[nr][nc] = true;
							}
						}
					}
				}
				sec++;
			}
		}
	}
	return;
}

void brid_len(int a, int b) {
	for (int i = 0; i < island[a].size(); ++i) {
		for (int j = 0; j < island[b].size(); ++j) {
			int distance = abs(island[a][i].first - island[b][j].first) + abs(island[a][i].second - island[b][j].second);
			ans = ans > distance ? distance : ans;
		}
	}
	return;
}