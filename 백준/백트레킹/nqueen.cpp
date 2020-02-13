#include <iostream>
#include <algorithm>
#include <cstring> 

using namespace std;


int N;
int col[20];
int cnt = 0; 


bool promising(int i) {


	for (int j = 1; j < i; j++) {
		if (col[j] == col[i] || (abs(col[j] - col[i]) == (i - j))) {
			return false;
		}
	}

	return true;

}


void dfs(int i) {

	if (i == N + 1) {
		cnt += 1;
		return;
	}


	for (int j = 1; j <= N; j++) {
		
		col[i] = j;

		if (promising(i)) {
			dfs(i + 1);
		}
	}

}



int main() {

	memset(col, 0, sizeof(col));

	cin >> N;

	dfs(1);

	cout << cnt; 


}
