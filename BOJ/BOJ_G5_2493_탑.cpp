#include <iostream>
#include <stack>

using namespace std;

int n; // ž�� ��
stack<pair<int, int>> st; //����,��ȣ

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	st.push({ 100000001,0 });
	cin >> n;
	for (int i = 1; i <= n; i++) { // ���̴� 1���� ����
		int height;
		cin >> height;
		while (st.top().first < height) {
			st.pop();
		}
		cout << st.top().second << ' ';
		st.push({ height,i });
	}

	return 0;
}