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
	// ax + b�� ���� 
	// ���������� ���·� ������ ��, 
	// ��� ���� ������ A 
	// ���� ���� ���� �ٸ��� B
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
		if ((vec[2] - vec[1]) % (vec[1] - vec[0]) != 0) { //������ �������� ������ a�� ������ �ƴϹǷ� B
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