#include <iostream>
#include <vector>

using namespace std;

void input();
void solve();

int N;
vector<int> vec;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		vec.push_back(x);
	}
	return;
}

void solve() {
	input();
	// ax + b의 형태 
	// 연립방정식 형태로 나왔을 때, 
	// 모든 식이 같으면 A 
	// 다음 식이 값과 다르면 B
	if (N >= 2 && vec[0] == vec[1]) {
		for (int i = 2; i < N; ++i) {
			if (vec[0] != vec[i]) {
				cout << "B\n";
				return;
			}
		}
		cout << vec[0];
		return;
	}
	else if (N <= 2) {
		cout << "A\n";
		return;
	}
	else {
		int a, b;
		// a * vec[0] + b = vec[1];
		// a * vec[1] + b = vec[2];
		// a * (vec[1] - vec[0]) = vec[2] - vec[1];
		a = (vec[2] - vec[1]) / (vec[1] - vec[0]);
		if ((vec[2] - vec[1]) % (vec[1] - vec[0]) != 0) { //나누어 떨어지지 않으면 a가 정수가 아니므로 B
			cout << "B\n";
			return;
		}
		b = vec[1] - a * vec[0];
		for (int i = 2; i < N - 1; ++i) {
			if ((vec[i] * a + b) != vec[i + 1]) {
				cout << "B\n";
				return;
			}
		}
		cout << (vec[N - 1] * a + b) << '\n';
	}

	return;
}