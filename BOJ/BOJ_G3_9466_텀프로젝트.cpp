#include <iostream>
#include <cstring>

using namespace std;

void input();
void solve();
void dfs(int x);

int TC, N, ans;
int arr[100001];
bool visit[100001];
bool done[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> TC;
	for (int tc = 0; tc < TC; ++tc) {
		ans = 0;
		memset(visit, false, sizeof(visit));
		memset(done, false, sizeof(done));
		input();
		solve();
		cout << N - ans << '\n';
	}
	return 0;
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
}

void solve() {
	for (int i = 1; i <= N; ++i) {
		if (!visit[i]) {
			if (arr[i] == i) { // 자기자신일때(혼자 1팀일때)
				visit[i] = true;
			}
			dfs(i);
		}
	}
}

void dfs(int x) {
	visit[x] = true;
	int next = arr[x];

	if (!visit[next]) {
		dfs(next);
	}
	else if (!done[next]) {
		for (int i = next; i != x; i = arr[i]) {
			ans++;
		}ans++;
	}

	done[x] = true;
}