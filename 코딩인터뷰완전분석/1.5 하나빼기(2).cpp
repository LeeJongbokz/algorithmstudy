#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void swap(string& a, string& b) {

	string temp;
	temp = a;
	a = b;
	b = temp;

}

bool compare1(string a, string b) {

	bool result = true;

	int len1 = a.size();
	int len2 = b.size();

	for (int i = 0; i < len1; i++) {
		if (i == len1 - 1) {
			a.erase(i, 1);
			break;
		}

		if (a[i] != b[i]) {
			a.erase(i, 1);
			break;
		}
	}

	for (int i = 0; i < len2; i++) {
		if (a[i] != b[i]) {
			result = false;
			break;
		}
	}

	return result;

}

bool compare0(string a, string b) {

	bool result = true; 

	int len1 = a.size();

	int diff = 0;

	for (int i = 0; i < len1; i++) {
		if (a[i] != b[i]) {
			diff += 1;
		}
	}

	if (diff >= 2) {
		result = false;
	}

	return result; 
}


int main() {

	bool isEditable = true; 

	string str1;
	cin >> str1;

	string str2;
	cin >> str2;

	if (str1.size() < str2.size()) {
		swap(str1, str2);
	}

	int len1 = str1.size();
	int len2 = str2.size();

	if (abs(len1 - len2) >= 2) {
		isEditable = false;
	}
	else if (abs(len1 - len2) == 1) {

		isEditable = compare1(str1, str2);


	}else{
	   
		isEditable = compare0(str1, str2);
	
	}

	if (isEditable == true) {
		cout << "편집 횟수가 1회 이내입니다.";
	}
	else {
		cout << "편집 횟수가 1회 이내가 아닙니다.";
	}



}
