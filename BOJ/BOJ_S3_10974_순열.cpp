#include <iostream>
#include <vector>
#include <algorithm> 
#define endl '\n'
using namespace std;

int n;
int v[10];
bool visited[10];
int result[10];

void permutation(int depth) {
    if (depth == n) {
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            result[depth] = v[i];
            permutation(depth + 1);
            visited[i] = 0;
        }
    }

}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    permutation(0);
        
}