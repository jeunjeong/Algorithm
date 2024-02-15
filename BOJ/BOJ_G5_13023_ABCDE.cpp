#include <iostream>
#include <vector>

using namespace std;

int N, M, ans = 0;
bool visit[2001];
vector<int> people[2001];

void input();
void solve();
void DFS(int depth, int cur);

int main() {
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
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		people[a].push_back(b);
		people[b].push_back(a);
	}
}

void solve() {
	for (int i = 0; i < N; i++){
		visit[i] = true;
		DFS(0, i);
		visit[i] = false;
		if (ans) break;
	}
}

void DFS(int depth, int cur) {
	if (depth == 4) {
		ans = 1;
		return;
	}
	for (int i = 0; i < people[cur].size(); ++i) {
		if (!visit[people[cur][i]]) {
			visit[people[cur][i]] = true;
			DFS(depth + 1, people[cur][i]);
			visit[people[cur][i]] = false;
		}
	}
}