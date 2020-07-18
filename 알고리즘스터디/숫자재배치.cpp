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
	
	// 첫 글자가 0이면 리턴함
	if (result[0] == '0') {
		return;
	}
	
	// 길이가 len이 되면 검사를 함
	if (pos == len) {
		int numC = stoi(result);
		int numB = stoi(B);

		if (numC <= numB) {
			isExist = true; 
			maxNum = max(maxNum, numC);
		}

		return; 
	}


	// 재귀 함수에서 백트레킹으로 result에 문자를 하나씩 더함
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

	// A와 B 입력
	cin >> A >> B;
	
	// A의 길이 저장
	len = A.size();
	
	// 재귀 함수 진입
	recursive(0);


	if (isExist == true) {
		cout << maxNum;
	}
	else {
		cout << -1;
	}


}
