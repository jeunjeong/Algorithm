#include <iostream>

#define endl '\n'
using namespace std;

int N;
bool visited[10];
int input[10];
int result[10];

void combination(int cnt, int index);

int main() {
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> input[i];
    }
    combination(0, 0);
    return 0;
}

void combination(int cnt, int index){
    if(cnt == N){
        for(int i = 0; i < N; ++i){
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < N; ++i){
        if(!visited[i]){
            visited[i] = true;
            result[cnt] = input[i];
            combination(cnt+1, i+1);
            visited[i] = false;
        }
    }
}