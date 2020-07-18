#include <iostream>
#include <string>
#include <algorithm>
#include <cstring> 

using namespace std;

const int INF = 999999999;

string result;
int len;
bool check[20];

string A;
string B;
int maxNum = -INF;
bool isExist = false;

void recursive(int pos) {
	
	if (result[0] == '0') {
		return;
	}

	if (pos == len) {
		int numC = stoi(result);
		int numB = stoi(B);

		if (numC <= numB) {
			isExist = true; 
			maxNum = max(maxNum, numC);
		}

		return; 
	}


	for (int i = 0; i < len; i++) {
		if (check[i] == false) {
			check[i] = true;
			result += A[i];
			recursive(pos + 1);
			result.pop_back();
			check[i] = false;
		}
	}


}


int main() {

	memset(check, false, sizeof(check));

	cin >> A >> B;
	len = A.size();
	
	recursive(0);


	if (isExist == true) {
		cout << maxNum;
	}
	else {
		cout << -1;
	}


}
