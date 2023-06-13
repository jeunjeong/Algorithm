#include <iostream>
#include <queue>

#define endl '\n'
using namespace std;

long long find_Decrease(int N);

int main(void){
    int N;
    cin >> N;
    long long result = find_Decrease(N);
    cout << result;
    return 0;
}

long long find_Decrease(int N){
    //10보다 작은 경우 그 자체로 감소하는 수 이므로 바로 리턴
    if(0 <= N && N < 10) return N;
    //10보다 큰 경우
    else {
        // N이 10 이상일 경우만 비교하므로 
        int cnt = 9;
        //감소하는 수들이 들어갈 큐 생성
        queue<long long> que;
        for(int i = 1; i < 10; ++i){
            que.push(i);
        }
        //종료조건 1) cnt==N이면 큐에서 꺼낸 수 리턴
        while(true){
            //큐의 제일 앞 숫자 꺼냄
            long long out = que.front();
            que.pop();
            //9876543210 이상일 경우 더이상 감소하는 수가 존재하지 않으므로 -1 리턴
            if(out >= 9876543210) return -1;
            //꺼낸 숫자의 1의자리수만 꺼냄
            // ex)432를 꺼낸 경우 다음에는 4320, 4321만 큐에 들어갈 수 있으므로 1의자리수인 '2'만 비교하면 됨 
            int num = out % 10;
            // ex)432가 나온 경우 2보다 작은 자리수만 1의자리에 들어갈 수 있으므로 
            for(int i = 0; i < num; ++i){
                // 
                que.push(out * 10 + i);
                cnt++;
                if(cnt == N){
                    return que.back();
                }
            }
        }
        return -1;
    }
}