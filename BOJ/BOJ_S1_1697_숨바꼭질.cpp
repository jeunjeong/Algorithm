#include <iostream>
#include <queue>
using namespace std;

int A, B, ans = 0;
bool visit[200001] = { false, };
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> A >> B;
	solve();
	cout << ans;
}

void solve() {
	queue<int> Q;
	Q.push(A);
	visit[A] = true;
	while (!Q.empty()) {
		int size = Q.size();
		for (int i = 0; i < size; ++i) {
			int x = Q.front();
			if (x == B) {
				return;
			}
			Q.pop();
			if (1 <= x && x < 100001 && !visit[x - 1]) {
				Q.push(x - 1);
				visit[x - 1] = true;
			}
			if (-1 <= x && x < 99999 && !visit[x + 1]) {
				Q.push(x + 1);
				visit[x + 1] = true;
			}
			if (0 <= x && x < 100000 && !visit[2 * x]) {
				Q.push(2 * x);
				visit[2 * x] = true;
			}
		}
		ans++;
	}
}