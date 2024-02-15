#include <iostream>
#include <algorithm>

using namespace std;

int N, ans = 0;
int arr[2000];

void input();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
}

void solve() {
	sort(arr, arr + N);
	for (int x = 0; x < N; ++x) {
		int a = 0, b = N - 1, sum;
		while (a < b) {
			if (a == x) {
				a++;
				continue;
			}
			else if (b == x) {
				b--;
				continue;
			}
			sum = arr[a] + arr[b];
			if (sum == arr[x]) {
				ans++;
				break;
			}
			else if (sum < arr[x]) a++;
			else b--;
		}
	}
	cout << ans;
} 