#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	string s1, s2;
	cin >> s1 >> s2;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	int len1 = s1.size();
	int len2 = s2.size();

	bool isRotate = true;

	if (len1 == len2) {
		for (int i = 0; i < len1; i++) {
			if (s1[i] != s2[i]) {
				isRotate = false;
				break;
			}
		}
	}
	else {
		isRotate = false;
	}

	if (isRotate) {
		cout << "회전 시킨 결과입니다.";
	}
	else {
		cout << "회전 시킨 결과가 아닙니다.";
	}


}
