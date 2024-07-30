#include <iostream>
#include <stack>

using namespace std;

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

void solve() {
	stack<char> sta;
	bool visit[30];
	string str;
	cin >> str;
	int sum = 0, num = 1;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '(') {
			sta.push(str[i]);
			num *= 2;
		}
		else if (str[i] == '[') {
			sta.push(str[i]);
			num *= 3;
		}
		else if (str[i] == ')') {
			if (!sta.empty() && sta.top() == '(') {
				if (str[i - 1] == '(') {
					sum += num;
				}
				sta.pop();
				num /= 2;
			}
			else {
				cout << '0' << '\n';
				return;
			}
		}
		else if (str[i] == ']') {
			if (!sta.empty() && sta.top() == '[') {
				if (str[i - 1] == '[') {
					sum += num;
				}
				sta.pop();
				num /= 3;
			}
			else {
				cout << '0' << '\n';
				return;
			}
		}
	}
	if (sta.empty()) {
		cout << sum << '\n';
	}
	else {
		cout << '0' << '\n';
		return;
	}
}