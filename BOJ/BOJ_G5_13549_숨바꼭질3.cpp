#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, ans;
int visit[100001];

void bfs(void);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	bfs();
	cout << visit[K];
	return 0;
}

void bfs(void) {
	fill(visit, visit + 100001, 100000);
	queue<pair<int, int>> Q;
	Q.push({ N,0 });
	visit[N] = 0;
	while (!Q.empty()) {
		pair<int, int> x = Q.front();
		
		Q.pop();
		for (int d = 0; d < 3; ++d) {
			int minus = x.first - 1;
			if (0 <= minus && minus <= 100000 && visit[minus] > x.second + 1) {
				Q.push({ minus, x.second + 1 });
				visit[minus] = x.second + 1;
			}
			int plus = x.first + 1;
			if (plus <= 100000 && visit[plus] > x.second + 1) {
				Q.push({ plus, x.second + 1 });
				visit[plus] = x.second + 1;
			}
			int move = 2 * x.first;
			if (move <= 100000 && visit[move] > x.second) {
				Q.push({ move, x.second });
				visit[move] = x.second;
			}
		}
	}
}
