#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

int main(void) {

	vector<int> vec; //vector<�ڷ���> �����̸� ���� ����
	vector<int> vec2(5, 2); //2�� �ʱ�ȭ�� 5���� ���Ҹ� ������ ���� v
	// =vec.assign(5,2);
	vector<int> vec3(vec2); //vec2�� ������ vec3, ���������̹Ƿ� �����Ͱ��� ���ο� �޸𸮰����� ����

	cout << vec2.front() << endl; //ù��° ���� ����
	cout << vec2.back() << endl; //������ ���� ����
	vec2.begin(); //ù��° ������ �ּҰ�
	vec2.end(); //������ ������ ������ ����Ű�� �ּҰ�  
	vec2.push_back(7); // �������� ���� 7 ���� 
	vec2.pop_back(); // �������� ���� ���� 

	cout << "vec3 size : " << vec3.size() << endl;
	cout << "vec3 capacity : " << vec3.capacity() << endl;
	vec3.clear(); //��� ���� ����, �޸𸮴� �״�� 
	cout << "vec3 size : " << vec3.size() << endl;
	cout << "vec3 capacity : " << vec3.capacity() << endl;
	
	return 0;
}
