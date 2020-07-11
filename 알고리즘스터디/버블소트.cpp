#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	int N;
	cin >> N;

	vector<pair<int, int>> v;
	int result = 0; 

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(make_pair(num, i));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		result = max(result, v[i].second - i);
	}

	cout << result + 1;


}
