#include <iostream>
#include <cstring>

using namespace std;

bool taken[10] = { 0 };
int C, n, m;
bool areFriends[10][10] = { 0 };

int countPairings(bool taken[10]) {

	bool finished = true;

	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			finished = false;
		}
	}

	if (finished) {
		return 1;
	}

	int ret = 0; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!taken[i] && !taken[j] && areFriends[i][j]) {
				taken[i] = taken[j] = true;
				cout << "Pair: " << i << " " << j << '\n';
				ret += countPairings(taken);
				taken[i] = taken[j] = false;
			}
		}
	}

	return ret; 

}

int main() {
	
	cin >> C;

	for (int i = 1; i <= C; i++) {
		cin >> n >> m;

		for (int j = 0; j < n; j++) {
			taken[j] = false;
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				areFriends[j][k] = false;
			}
		}


		for (int j = 1; j <= m; j++) {
			int studentA, studentB;
			cin >> studentA >> studentB;
			areFriends[studentA][studentB] = true;
		}

		int result = countPairings(taken);

		cout << result << '\n';
	}




}
