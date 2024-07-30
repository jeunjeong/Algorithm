#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

void input();
void solve();
void bfs(int k, int v);

int N, Q, ans;
bool visit[5001];
vector<pair<int,int>> link[5001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N >> Q;
	int a, b, c;
	for (int i = 0; i < N-1; ++i) {
		cin >> a >> b >> c;
		link[a].push_back({ b,c });
		link[b].push_back({ a,c });
	}
	return;
}

void solve() {
	input();
	int k, v;
	for (int i = 0; i < Q; ++i) {
		cin >> k >> v;
		ans = 0;
		memset(visit, false, sizeof(visit));
		bfs(k, v);
		cout << ans << '\n';
	}
	return;
}

void bfs(int k, int v) {
	queue<int> Q;
	visit[v] = true;
	Q.push(v);
	while (!Q.empty()) {
		int start = Q.front();
		Q.pop();
		//cout << start << '\n';
		for(int i = 0; i < link[start].size(); ++i){
			pair<int, int> x = link[start][i];
			if (!visit[x.first] && x.second >= k) { // 방문안했고 k보다 값이 크면 
				visit[x.first] = true;
				Q.push(x.first);
				ans++;
			}
		}
	}
	return;
}