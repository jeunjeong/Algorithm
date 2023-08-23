#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

int main(void) {

	vector<int> vec; //vector<자료형> 벡터이름 으로 선언
	vector<int> vec2(5, 2); //2로 초기화된 5개의 원소를 가지는 벡터 v
	// =vec.assign(5,2);
	vector<int> vec3(vec2); //vec2를 복사한 vec3, 깊은복사이므로 데이터값을 새로운 메모리공간에 복사

	cout << vec2.front() << endl; //첫번째 원소 참조
	cout << vec2.back() << endl; //마지막 원소 참조
	vec2.begin(); //첫번째 원소의 주소값
	vec2.end(); //마지막 원소의 다음을 가리키는 주소값  
	vec2.push_back(7); // 마지막에 원소 7 삽입 
	vec2.pop_back(); // 마지막에 원소 제거 

	cout << "vec3 size : " << vec3.size() << endl;
	cout << "vec3 capacity : " << vec3.capacity() << endl;
	vec3.clear(); //모든 원소 제거, 메모리는 그대로 
	cout << "vec3 size : " << vec3.size() << endl;
	cout << "vec3 capacity : " << vec3.capacity() << endl;
	
	return 0;
}
