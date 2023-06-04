#include <iostream>

#define endl '\n'
using namespace std;

int N;
int input[10];
int result[10];
bool visited[10];

void permutation(int cnt);

int main(){
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> input[i];
    }
    permutation(0);
    return 0;
}

void permutation(int cnt){
    // 기저조건 : n개 선택 완료
    if (cnt == N){
        for (int i = 0; i < N; ++i){
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }
    // 선택
    for (int i = 0; i < N; ++i){
        // 선택되지 않은 수 중에서
        if (!visited[i]){
            // 선택
            visited[i] = true;
            result[cnt] = input[i];
            // 다음거 선택하러 가기
            permutation(cnt + 1);
            // 선택 해제(다음 for문을 위해서)
            visited[i] = false;
        }
    }
}