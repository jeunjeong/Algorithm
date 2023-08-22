#include <iostream> 
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;

pair<int, string> p;
vector<pair<int, string>> vec;

bool compare_int_desc(int a, int b);
int sort_int(void);
bool compare_pair(pair<int, string> a, pair<int, string> b);
int sort_pair(void);

int main(void) {
	sort_pair();

	return 0; 
}

bool compare_int_desc(int a, int b) {
	return a > b;
}

int sort_int(void) {
	int arr[10] = { 0,9,1,8,2,7,3,6,4,5 };
	sort(arr, arr + 10);

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}

	cout << endl;
	sort(arr, arr + 10, compare_int_desc);

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}

bool compare_pair(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

int sort_pair(void) {
	vec.push_back({ 90,"Â¯±¸" });
	vec.push_back({ 80,"À¯¸®" });
	vec.push_back({ 90,"À¯¸®" });
	vec.push_back({ 88,"Â¯±¸" });
	vec.push_back({ 80,"Ã¶¼ö" });
	vec.push_back({ 80,"¸Í±¸" });
	cout << "Á¤·Ä Àü : " << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].first << vec[i].second << endl;
	}

	cout << "±âº» Á¤·Ä : " << endl;
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].first << vec[i].second << endl;
	}

	cout << "compare Á¤·Ä : " << endl;
	sort(vec.begin(), vec.end(), compare_pair);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].first << vec[i].second << endl;
	}
	return 0;
}