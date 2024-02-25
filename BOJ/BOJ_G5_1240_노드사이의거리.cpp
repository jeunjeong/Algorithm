#include <iostream>
#include <cstring>

using namespace std;

void solve();
void dfs(int start, int fin, int depth);

int N, M,  ans;
int node[1001][1001] = { 0, };
bool visit[1001] = { false, };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void solve() {
	cin >> N >> M;
	for (int i = 1; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a][b] = c;
		node[b][a] = c;
	}
	for (int tc = 0; tc < M; ++tc) {
		int start, finish;
		cin >> start >> finish;
		ans = 10000000;
		memset(visit, false, sizeof(visit));
		dfs(start, finish, 0);
		cout << ans << '\n';
	}
	return;
}

void dfs(int start, int fin,int depth) {
	if (start == fin) {
		if (depth < ans) {
			ans = depth;
		}
		return;
	}
	visit[start] = true;
	for (int i = 1; i <= N; ++i) {
		if (!visit[i] && node[start][i] != 0) {
			dfs(i, fin, depth + node[start][i]);
		}
	}
}