#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void input();
void solve();
void dfs(int start, int length);

int N, ans, fin;
bool visit[10001] = { false, };
vector<pair<int, int>> node[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N;
	for (int l = 1; l < N; ++l) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}
}

void solve() {
	input();
	dfs(1, 0);
	ans = 0;
	memset(visit, false, sizeof(visit));
	dfs(fin, 0);
	cout << ans;
}

void dfs(int start, int length) {
	if (visit[start]) {	
		return;
	}
	if (ans < length) {
		ans = length;
		fin = start;
	}
	visit[start] = true;
	for (int i = 0; i < node[start].size(); ++i) {
		dfs(node[start][i].first, length + node[start][i].second);
	}
}