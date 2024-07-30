#include <iostream>
#include <cstring>
using namespace std;

struct shark {
	int row;
	int col;
	int dir;
	bool alive;
};

int N, M, K, ans;
int dr[5] = { 0, -1, 1, 0, 0 }; // �� �� �� �� ����
int dc[5] = { 0, 0, 0, -1, 1 };
int shark_dir[401][5][5];
pair<int, int> map[20][20]; // <����ȣ, �����ð�>
bool visit[20][20];
shark sharks[401];

void input();
void solve();
bool simulation();

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
		for (int c = 0; c < N; ++c) {
			int buf;
			cin >> buf;
			if (buf != 0) {
				sharks[buf] = { r, c, 0, true };
				map[r][c] = { buf, K };
			}
			else {
				map[r][c] = { 0, 0 };
			}
		}
	}
	for (int i = 1; i <= M; ++i) {
		int d;
		cin >> d;
		sharks[i].dir = d;
	}
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= 4; ++j) {
			for (int k = 1; k <= 4; ++k) {
				cin >> shark_dir[i][j][k];
			}
		}
	}
	return;
}

void solve() {
	input();
	if (simulation()) {
		cout << ans;
	}
	else {
		cout << "-1";
	}
	return;
}

bool simulation() {
	while (ans <= 1000) {
		memset(visit, false, sizeof(visit));
		//cout << ans << '\n';
		bool flag = true;
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < N; ++c) {
				//cout << map[r][c].first << ","  << map[r][c].second << ' ';
				if (map[r][c].first != 0) {
					if (map[r][c].second == 0) {
						map[r][c] = { 0, 0 };
					}
					else {
						visit[r][c] = true;
						map[r][c].second -= 1;
					}
				}
			}
			//cout << '\n';
		}
		//cout << "------------------------------------------------\n";
		for (int i = M; i > 0; --i) {
			if (!sharks[i].alive) continue; // ���� ���� �ǳʶ�
			if (flag && i > 1 && sharks[i].alive) { // flag�� true�̰� 1���� �ƴ� �ٸ� �� ��������� flag�� false 
				flag = false;
			}
			int row = sharks[i].row;
			int col = sharks[i].col;
			int dir = sharks[i].dir;
			int xr, xc, xd;
			bool move = false, x_save = false;
			for (int d = 1; d <= 4; ++d) {
				int nd = shark_dir[i][dir][d]; 
				int nr = row + dr[nd];
				int nc = col + dc[nd];
				
				if (0 <= nr && nr < N && 0 <= nc && nc < N){
					if (map[nr][nc].first == 0) { // ��ĭ�̸� �̵�
						sharks[i] = { nr, nc, nd, true };
						map[nr][nc] = { i, K };
						d = 5;
						move = true;
					}
					else if (!x_save && map[nr][nc].first == i) { // �ڱ� ������ �ִ� ĭ ����
						xr = nr;
						xc = nc;
						xd = nd;
						x_save = true;
					}
					else if (map[nr][nc].first > i && map[nr][nc].second == K && !visit[nr][nc]) { // ���ÿ� �̵��ϸ� 
						int die = map[nr][nc].first; //������ ��� ����
						//cout << "die : " << die << '\n';
						sharks[die].alive = false;
						sharks[i] = { nr, nc, nd, true };
						map[nr][nc] = { i, K };
						d = 5;
						move = true;
					}
				}
			}
			if (!move) { // �̵����� �������� �ڱ� ������ �ִ� ĭ���� ���ư�
				sharks[i] = { xr, xc, xd, true };
				//cout <<i << " -> " <<  xr << " : " << xc << '\n';
				map[xr][xc].second = K;
			}
		}
		if (flag) { // ��������, 1�� �� ���������� ����
			//cout << "hi \n";
			return true;
		}
		ans++;
	}
	return false;
}