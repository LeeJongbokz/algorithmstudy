#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<long long> v;

	int maxCnt = -1;
	int cnt = 1;
	long long result = 0; 

	for (int i = 1; i <= N; i++) {
		long long num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {

		if (i == v.size() - 1) {

			if (maxCnt < cnt) {
				result = v[i];
			}

			break;

		}

		if (v[i] == v[i + 1]) {
			cnt += 1;
		}
		else {

			if (maxCnt < cnt) {
				maxCnt = cnt;
				result = v[i];
			}

			cnt = 1;

		}
	}


	cout << result;


}
