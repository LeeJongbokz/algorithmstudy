#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;
	cin >> str;

	string result;

	int len = str.size();

	char c = str[0];
	int num = 1;

	for (int i = 0; i < len - 1; i++) {
		if (str[i] == str[i + 1]) {
			num += 1;
		}
		else {
			result += c;
			result += to_string(num);
			c = str[i + 1];
			num = 1;
		}

		if (i == len - 2) {
			result += c;
			result += to_string(num);
			break;
		}
	}

	if (str.size() < result.size()) {
		cout << str;
	}
	else {
		cout << result; 
	}



}
