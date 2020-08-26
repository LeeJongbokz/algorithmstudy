#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int INF = 999999;

int minlen = INF;

int main() {

	string s;
	cin >> s;

	int len = s.size();

	vector<string> v;

	for (int i = 1; i <= len; i++) {
		
		v.clear();

		for (int j = 0; j < len; j += i) {
			string temp = s.substr(j, i);
			v.push_back(temp);
		}

		string tempResult;
		int vlen = v.size();

		string str = v[0];
		int cnt = 1;

		if (vlen == 1) {
			tempResult += v[0];
		}
		else {
			for (int j = 0; j < vlen - 1; j++) {
				if (v[j] == v[j + 1]) {
					cnt += 1;
				}
				else {
					if (cnt == 1) {

						tempResult += str;
						str = v[j + 1];

					}
					else {
						tempResult += to_string(cnt);
						tempResult += str;
						str = v[j + 1];
						cnt = 1;
					}
				}

				if (j == vlen - 2) {
					if (cnt == 1) {

						tempResult += str;

					}
					else {
						tempResult += to_string(cnt);
						tempResult += str;
					}
				}

			}
		}

		int templen = tempResult.size();

		minlen = min(minlen, templen);
	}

	cout << minlen;

}
