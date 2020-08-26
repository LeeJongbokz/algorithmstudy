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
		if (s1.substr(0) == s2) {
			isRotate = true;
		}
		else {
			isRotate = false;
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
