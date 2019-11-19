#include <iostream>
#include <cstring>

using namespace std;

int n, m;
bool areFriends[10][10];
bool taken[10] = { 0 };

int countPairings(bool taken[10]) {
	int firstFree = -1;

	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
		    break;
		}
	}

	if (firstFree == -1) return 1;
	int ret = 0; 

	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			cout << firstFree << " " << pairWith << '\n';
			ret += countPairings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret; 

}

int main() {

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {

		memset(taken, false, sizeof(taken));
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				areFriends[j][k] = false;
			}
		}

		cin >> n >> m;

		for (int j = 1; j <= m; j++) {
			int studentA, studentB;
			cin >> studentA >> studentB;
			areFriends[studentA][studentB] = true;
		}


		int result = countPairings(taken);

		cout << result << '\n';

	}



}
