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
			int num1 = v[j] + 1;
			int num2 = v[j] + 5;
			int num3 = v[j] + 10;
			int num4 = v[j] + 50;

			temp.push_back(num1);
			temp.push_back(num2);
			temp.push_back(num3);
			temp.push_back(num4);
		}

		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());
		v = temp;
	}

	cout << v.size();


}
