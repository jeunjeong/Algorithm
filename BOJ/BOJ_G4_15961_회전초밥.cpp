#include <iostream>
#include <vector>

using namespace std;

int N, d, k, c, ans;
int plate[4000000];
int sushi[3001];
void input();
void solve();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}

void input() {
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; ++i) {
		cin >> plate[i];
	}
	for (int i = N; i < N + k; ++i) {
		plate[i] = plate[i - N];
	}
}

void solve() {
	int count = 0;
	for (int start = 0; start < k; ++start) {
		int x = plate[start];
		if (sushi[x] == 0) {
			count++;
		}
		sushi[x]++;

	}
	if (sushi[c] == 0) {
		ans = count + 1;
	}
	else {
		ans = count;
	}
	for (int i = 1; i < N; ++i) {
		int next_idx = k + i - 1;
		int before = plate[i - 1];
		int next = plate[next_idx];
		sushi[before] --;
		if (sushi[before] == 0) {
			count--;
		}
		sushi[next] ++;
		if (sushi[next] == 1) {
			count++;
		}

		if (sushi[c] == 0) {
			ans = count >= ans ? count + 1 : ans;
		}
		else {
			ans = count > ans ? count : ans;
		}
	}
	cout << ans;
}