#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 999999999;
vector<int> answer;

void recursive(vector<int>& A, vector<int>& B, int apos, int bpos, vector<int>& result) {

	if (apos == A.size() && bpos == B.size()) {
		answer = result;
		return; 
	}


	int input;

	if (result.empty()) {
		int numA = A[apos];
		int numB = B[bpos];

		if (numA < numB) {
			input = numA;
			apos += 1;
		}
		else if (numB < numA) {
			input = numB;
			bpos += 1;
		}
		else {
			input = numB;
			apos += 1;
			bpos += 1;
		}

		result.push_back(input);
		recursive(A, B, apos, bpos, result);

	}
	else {

		int numA = INF;
		int numB = INF;

		int lastNum = result.back();

		
		if (0 <= apos && apos <= A.size() - 1) {
				numA = A[apos];
		}

		if (0 <= bpos && bpos <= B.size() - 1) {
				numB = B[bpos];
		}

		if ((numA < numB) && (lastNum < numA) && (numA != INF)) {
				input = numA;
				apos += 1;
		}else if ((numB < numA) && (lastNum < numB) && (numB != INF)) {
				input = numB;
				bpos += 1;
		}else if ((numA == numB) && (lastNum < numA) && (numA != INF) && (numB != INF)) {
				input = numA;
				apos += 1;
				bpos += 1;
		}

		result.push_back(input);

		recursive(A, B, apos, bpos, result);

	}



}






int main() {

	int C;
	cin >> C;

	for (int i = 1; i <= C; i++) {
		int n, m;
		cin >> n >> m;

		vector<int>A;
		vector<int>B;

		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			A.push_back(num);
		}

		for (int j = 1; j <= m; j++) {
			int num;
			cin >> num;
			B.push_back(num);
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int apos = 0;
		int bpos = 0;
		vector<int> result;

		recursive(A, B, apos, bpos, result);

		cout << answer.size();
	}


}
