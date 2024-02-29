#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void input();
void solve();

int N, root, del, ans;
bool check_die[50];
vector<int> node[51];

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
		if (x != -1) {
			node[x].push_back(i);
		}
		else {
			root = i;
			node[50].push_back(i);
		}
	}
	cin >> del;
	return;
}

void solve() {
	input();
	if (del == root) {
		cout << 0 << '\n';
		return;
	}
	queue<int> Q;
	Q.push(del);
	check_die[del] = true;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		int siz = node[x].size();
		while (--siz >= 0) {
			Q.push(node[x][siz]);
			check_die[node[x][siz]] = true;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (!check_die[i] && node[i].size() == 0) {
			ans++;
		}
		else if(!check_die[i]) {
			for (int j = 0; j < node[i].size(); ++j) {
				if (!check_die[node[i][j]]) break;
				if (j == node[i].size() - 1 && check_die[node[i][j]]) {
					ans++;
				}
			}
		}
	}
	cout << ans << '\n';
	return;
}