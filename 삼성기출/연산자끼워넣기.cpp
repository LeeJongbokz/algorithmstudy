#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 1000000000;

int N;
vector<int> v;
vector<char> symbol;
bool check[20];
int maxNum = -INF;
int minNum = INF;
int symbolLen; 


void calculate(int result, int index) {

	if (index == N) {
		if (result > maxNum) {
			maxNum = result;
		}
		if (result < minNum) {
			minNum = result;
		}
		return; 

	}


	for (int i = 0; i < symbolLen; i++) {

		int remain;

		if (check[i] == false) {
			if (symbol[i] == '+') {
				result += v[index];
			}
			else if (symbol[i] == '-') {
				result -= v[index];
			}
			else if (symbol[i] == '*') {
				result *= v[index];
			}
			else if (symbol[i] == '/') {
				result /= v[index];
				remain = result % v[index];
			}

			check[i] = true;
			calculate(result, index + 1);
			check[i] = false;

			if (symbol[i] == '+') {
				result -= v[index];
			}
			else if (symbol[i] == '-') {
				result += v[index];
			}
			else if (symbol[i] == '*') {
				result /= v[index];
			}
			else if (symbol[i] == '/') {
				result = result*v[index]+remain;
			}




		}



	}


}


int main() {

	memset(check, false, sizeof(check));

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int plus, minus, multiply, divide = 0;
	cin >> plus >> minus >> multiply >> divide;
	
	for (int i = 0; i < plus; i++) {
		symbol.push_back('+');
	}

	for (int i = 0; i < minus; i++) {
		symbol.push_back('-');
	}

	for (int i = 0; i < multiply; i++) {
		symbol.push_back('*');
	}

	for (int i = 0; i < divide; i++) {
		symbol.push_back('/');
	}

	int start = v[0];
	symbolLen = symbol.size(); 


	calculate(start, 1);

	cout << maxNum << '\n';
	cout << minNum;


}
