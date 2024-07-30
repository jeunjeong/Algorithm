//#include <iostream>
//#include <queue> // priority_queue는 queue 헤더파일에 선언되어있다 
//// 이건 난수발생을 위한 헤더파일들! 
//#include <stdlib.h>
//#include <time.h>
//
//using namespace std;
//
//void queue_push(int N);
//void queue_pop();
//
//priority_queue<int> Q;
//
//int main() {
//	//time.h 헤더파일을 이용해서 
//	srand(time(NULL));
//	queue_push(5);
//	queue_pop();
//	return 0;
//}
//
//void queue_push(int N) {
//	for (int i = 0; i < N; ++i) {
//		//난수 생성 rand 함수와 100 까지의 난수만 발생시키기 위해 100으로 나눈 나머지 값을 저장
//		int N = rand() % 100;
//		Q.push(N);
//		cout << "input : " << N << '\n';
//	}
//	return;
//}
//void queue_pop() {
//	cout << "----------------\n";
//	cout << "Q 사이즈 : " << Q.size() << '\n';
//	cout << "----------------\n";
//	while (!Q.empty()) {
//		cout << "output : " << Q.top() << '\n';
//		Q.pop();
//	}
//	return;
//}
//
//
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int main() {
//    priority_queue<int> pq1, pq2;
//
//    cout << "input \n";
//    cout << "pq1 : 10 5 15 \n";
//    // pq1에 요소 추가
//    pq1.emplace(10);
//    pq1.emplace(5);
//    pq1.emplace(15);
//
//    cout << "pq2 : 40 25 30 \n";
//    // pq2에 요소 추가
//    pq2.emplace(40);
//    pq2.emplace(25);
//    pq2.emplace(30);
//
//    // pq1과 pq2 swap
//    pq1.swap(pq2);
//
//    // 각 큐 출력
//    cout << "output \n";
//    cout << "pq1: ";
//    while (!pq1.empty()) {
//        cout << pq1.top() << " ";
//        pq1.pop();
//    }
//    cout << '\n';
//    cout << "pq2: ";
//    while (!pq2.empty()) {
//        cout << pq2.top() << " ";
//        pq2.pop();
//    }
//    cout << '\n';
//
//    return 0;
//}
