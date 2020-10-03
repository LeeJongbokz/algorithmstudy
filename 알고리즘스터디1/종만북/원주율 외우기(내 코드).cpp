#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int cache[10010];

const int INF = 99999999;

int recursive(string str, int idx, int finalResult) {

	if (idx == str.size()) {
		return finalResult;
	}

	int ret = INF;

	if (cache[idx] != -1) {
		return cache[idx];
	}

	for (int i = 3; i <= 5; i++) {

		string temp = str.substr(idx, i);

		if (temp.size() != i) {
			continue;
		}

		bool isAllSame = true;
		bool isRiseorFall = true;
		bool isSubstitute = true;
		bool isArithmetic = true;

		int num = temp[0];

		for (int j = 1; j < temp.size(); j++) {
			if (num != temp[j]) {
				isAllSame = false;
				break;
			}
		}

		if (isAllSame == true) {
			ret = min(ret, recursive(str, idx + i, finalResult + 1));
		}

		if (temp[0] - temp[1] == 1) {

			for (int j = 1; j < temp.size() - 1; j++) {
				if (temp[j] - temp[j + 1] != 1) {
					isRiseorFall = false;
					break;
				}
			}
		}
		else if (temp[0] - temp[1] == -1) {

			for (int j = 1; j < temp.size() - 1; j++) {
				if (temp[j] - temp[j + 1] != -1) {
					isRiseorFall = false;
					break;
				}
			}
		}
		else {
			isRiseorFall = false;
		}

		if (isRiseorFall == true) {
			ret = min(ret, recursive(str, idx + i, finalResult + 2));
		}

		int even = temp[0];
		int odd = temp[1];

		for (int j = 2; j < temp.size(); j++) {
			if (j % 2 == 0 && even != temp[j]) {
				isSubstitute = false;
				break;
			}
			else if (j % 2 == 1 && odd != temp[j]) {
				isSubstitute = false;
				break;
			}
		}

		if (isSubstitute == true) {
			ret = min(ret, recursive(str, idx + i, finalResult + 4));
		}

		int gap = temp[0] - temp[1];

		for (int j = 1; j < temp.size() - 1; j++) {
			if (gap != (temp[j] - temp[j + 1])) {
				isArithmetic = false;
				break;
			}
		}

		if (isArithmetic == true) {
			ret = min(ret, recursive(str, idx + i, finalResult + 5));
		}

		ret = min(ret, recursive(str, idx + i, finalResult + 10));

	}

	return cache[idx] = ret;


}


int main() {

	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {

		string str;
		cin >> str;

		memset(cache, -1, sizeof(cache));

		int result = recursive(str, 0, 0);

		cout << result << '\n';
	}
	return 0;
}
