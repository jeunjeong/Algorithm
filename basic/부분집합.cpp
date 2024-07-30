#include <iostream>

#define endl '\n'
using namespace std;

int N;
int input[10];
int result[10];

void generateSubset(int cnt, int index){
    if(cnt == N){
        for(int i = 0; i < N; ++i){
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }
    generateSubset(cnt, index + 1);
    result[cnt] = input[index]; 
    generateSubset(cnt + 1, index + 1);   
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; ++i){
        cin >> input[i];
    }
    generateSubset(0, 0);
    return 0;
}