#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> v;

	v.push_back(1);
	v.push_back(5);
	v.push_back(10);
	v.push_back(50);

	for (int i = 2; i <= N; i++) {
		vector<int> temp;
		int len = v.size();

		for (int j = 0; j < len; j++) {
			
			// 해당하는 케이스를 모두 구해서 
			int num1 = v[j] + 1;
			int num2 = v[j] + 5;
			int num3 = v[j] + 10;
			int num4 = v[j] + 50;

			// temp 벡터에 저장함
			temp.push_back(num1);
			temp.push_back(num2);
			temp.push_back(num3);
			temp.push_back(num4);
		}

		// temp 벡터를 정렬함
		sort(temp.begin(), temp.end());
		// temp 벡터에서 중복값을 제거함
		temp.erase(unique(temp.begin(), temp.end()), temp.end());
		// temp 벡터를 v 벡터에 업데이트함
		v = temp;
	}

	cout << v.size();


}
