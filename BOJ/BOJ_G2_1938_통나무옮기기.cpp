#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

#define MAX 50
#define endl '\n'

using namespace std;

// 1. 배열 입력, B, E기둥 배열입력
// 2. B, E상태 확인 (true이면 세로, false이면 가로)
// 3. 상하좌우 함수 구현
// 4. 회전 함수 구현
// 5. BFS

struct position {
    int row;
    int column;
};

int N;
char matrix [MAX][MAX];
position bArray[3];
position eArray[3];

int main (void){
    cin >> N;
    int bCnt = 0;
    int eCnt = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >>  matrix[i][j]; // matrix 배열 입력
            if(matrix[i][j] == 'B'){ //값이 'B'일 경우 bArray에 추가
                bArray[bCnt]={i,j};
                bCnt++;
            }else if(matrix[i][j] == 'E'){ //값이 'E일 경우 eArray에 추가
                eArray[eCnt]={i,j};
                eCnt++;
            }
        }
    }


    /* 출력
    for(int i = 0; i < 3; ++i){
        cout << "bArray[" << i << "] row : " << bArray[i].row << " column : " << bArray[i].column << endl;
    }
    for(int i = 0; i < 3; ++i){
        cout << "eArray[" << i << "] row : " << eArray[i].row << " column : " << eArray[i].column << endl;
    }
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    */
    return 0;
}

//2. state check (true이면 세로 false이면 가로)
boolean checkState(position[] array){
    if(array[0].row == array[0].row) return true;
    else return false;
}

boolean simulation(int num) {
    switch(num){
    case 1: // UP 
        for(int i = 0; i < 3; ++i) {
            if(bArray[i].row <= 1 || matrix[bArray[i].row -1][bArray[i].column] == 1) return false;
        }
        break;
    case 2: // DOWN
        for(int i = 0; i < 3; ++i) {
            if(bArray[i].row >= N-1 || matrix[bArray[i].row +1][bArray[i].column] == 1) return false;
        }
        break;
    case 3: // LEFT
        for(int i = 0; i < 3; ++i) {
            if(bArray[i].column <= 1 || matrix[bArray[i].row][bArray[i].column-1] == 1) return false;
        }
        break;
    case 4: // RIGHT
        for(int i = 0; i < 3; ++i) {
            if(bArray[i].column >= N-1 || matrix[bArray[i].row -1][bArray[i].column] == 1) return false;
        }
        break;
    }
    return true;
}

int BFS(){
    queue<position> queue;
    queue.push({bArray[1].row,bArray[1].column});
    if(b_state) true_visit[bArray[1].row][bArray[1].column] = true;
    else false_visit[bArray[1].row][bArray[1].column] = true;
    while(queue.empty() == 0){

    }

    return 0;
}