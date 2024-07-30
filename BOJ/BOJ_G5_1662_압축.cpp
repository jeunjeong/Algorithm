#include <iostream>
#include <stack>

using namespace std;

void input();
int solve(int idx);


string str;
stack<char> sta;
bool visited[50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	cout << solve(0);
	return 0;
}

void input() {
	cin >> str;
}

int solve(int idx) {
	int cnt = 0;
	for (int i = idx; i < str.length(); i++) {
		char ch = str[i];
		if (ch == '(' && !visited[i]) {
			visited[i] = true;
			cnt--;
			cnt += (int)(str[i - 1] - '0') * solve(i + 1);
		}
		else if (ch == ')' && !visited[i]) {
			visited[i] = true;
			return cnt;
		}
		else if (!visited[i]) {
			visited[i] = true;
			cnt++;
		}
	}
	return cnt;

}