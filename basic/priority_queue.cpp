//#include <iostream>
//#include <queue> // priority_queue�� queue ������Ͽ� ����Ǿ��ִ� 
//// �̰� �����߻��� ���� ������ϵ�! 
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
//	//time.h ��������� �̿��ؼ� 
//	srand(time(NULL));
//	queue_push(5);
//	queue_pop();
//	return 0;
//}
//
//void queue_push(int N) {
//	for (int i = 0; i < N; ++i) {
//		//���� ���� rand �Լ��� 100 ������ ������ �߻���Ű�� ���� 100���� ���� ������ ���� ����
//		int N = rand() % 100;
//		Q.push(N);
//		cout << "input : " << N << '\n';
//	}
//	return;
//}
//void queue_pop() {
//	cout << "----------------\n";
//	cout << "Q ������ : " << Q.size() << '\n';
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
//    // pq1�� ��� �߰�
//    pq1.emplace(10);
//    pq1.emplace(5);
//    pq1.emplace(15);
//
//    cout << "pq2 : 40 25 30 \n";
//    // pq2�� ��� �߰�
//    pq2.emplace(40);
//    pq2.emplace(25);
//    pq2.emplace(30);
//
//    // pq1�� pq2 swap
//    pq1.swap(pq2);
//
//    // �� ť ���
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
