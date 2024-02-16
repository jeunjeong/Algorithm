#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input();
void solve();

int N, M, ans;
pair<int, int> start;
int dir;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int map[50][50];
bool visit[50][50];

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
	cin >> N >> M;
	cin >> start.first >> start.second >> dir;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			cin >> map[r][c];
			if (map[r][c] == 1) {
				visit[r][c] = true;
			}
		}
	}
}

void solve() {
	bool flag = true;
	while (flag) {
		//1�� : ���� ĭ�� ���� û�ҵ��� ���� ���, ���� ĭ�� û���Ѵ�.
		if (map[start.first][start.second] == 0 && !visit[start.first][start.second]) {
			visit[start.first][start.second] = true;
			//print();
			//cout << start.first << " : " << start.second << '\n';
			ans++;
		}
		//2�� : ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� �ִ��� Ȯ��
		for (int d = 3; d >= -1; d--) {
			//3�� : ���� ĭ�� �ֺ� 4ĭ �� û�ҵ��� ���� �� ĭ�� ���� ���
			if (d == -1) {
				int nd = (dir + 2) % 4; // �ڷ�
				int nr = start.first + dr[nd];
				int nc = start.second + dc[nd];
				if (0 <= nr && nr < N && 0 <= nc && nc < M && map[nr][nc] == 0) {
					start = { nr,nc }; // �ڷ� ��ĭ �̵� �� ��ġ ����
				}
				else {
					flag = false;
				}
			}
			else {
				int nr = start.first + dr[(d + dir) % 4];
				int nc = start.second + dc[(d + dir) % 4];
				if (0 <= nr && nr < N && 0 <= nc && nc < M && map[nr][nc] == 0 && !visit[nr][nc]) {
					start = { nr,nc }; // ��ġ ����
					dir = (d + dir) % 4; //�ٶ󺸴� ���� ����
					d = -2;
				}
			}
		}
	}
}

