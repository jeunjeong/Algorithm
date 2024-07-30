#include <iostream>
#include <vector>

using namespace std;

#define MAX(a,b) a>b?a:b

void input();
void solve();
void DP();

int N;
int T[1500001];
int P[1500001];
int res[1500002];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> T[i];
		cin >> P[i];
	}
	return;
}

void solve() {
	input();
	DP();
	cout << res[N+1];
	return;
}

void DP() {
	for (int i = 1; i <= N+1; ++i) {
		if (res[i] < res[i - 1]) {
			res[i] = res[i - 1];
		}
		int x = i + T[i];
		if (x <= N+1) {
			res[x] = MAX(res[i] + P[i] , res[x]);
		}
	}
	return;
}