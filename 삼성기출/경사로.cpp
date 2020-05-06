#include <iostream>
#include <cstring>

using namespace std;

int N, L;
int map[110][110];
int tempMap[110][110];
bool road[110][110];


bool ascend(int rowNum, int pos) {

	int length = L - 1;
	int next = pos - 1;

	while (length--) {

		if ((map[rowNum][next] == map[rowNum][pos]) && next >= 1 && road[rowNum][next] == false) {
			road[rowNum][next] = true;
		}
		else {
			return false;
		}

		next -= 1;

	}


	if (road[rowNum][pos] == false) {
		road[rowNum][pos] = true;
	}
	else {
		return false;
	}

	return true;

}


bool descend(int rowNum, int pos) {

	int length = L - 1;
	int next = pos + 1;

	while (length--) {

		if ((map[rowNum][next] == map[rowNum][pos]) && next <= N && road[rowNum][next] == false) {
			road[rowNum][next] = true;
		}
		else {
			return false;
		}

		next += 1;

	}


	if (road[rowNum][pos] == false) {
		road[rowNum][pos] = true;
	}
	else {
		return false;
	}

	return true;

}




bool isRow(int rowNum) {

	for (int i = 1; i <= N - 1; i++) {

		if (map[rowNum][i] == map[rowNum][i + 1]) {
			continue;
		}
		else if (map[rowNum][i] + 1 == map[rowNum][i + 1]) {
			bool result = ascend(rowNum, i);

			if (result == false) {
				return false; 
			}

		}
		else if (map[rowNum][i] - 1 == map[rowNum][i + 1]) {
			bool result = descend(rowNum, i+1);

			if (result == false) {
				return false;
			}
		}
		else {
			return false; 
		}
	}

	return true; 


}




int main() {

	int total = 0; 

	memset(road, false, sizeof(road));

	cin >> N >> L;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 1; i <= N; i++) {
		bool isRoad = isRow(i);

		if (isRoad == true) {
			total += 1;
		}

	}


	memset(road, false, sizeof(road));


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			tempMap[i][j] = map[j][i];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = tempMap[i][j];
		}
	}


	for (int i = 1; i <= N; i++) {
		bool isRoad = isRow(i);

		if (isRoad == true) {
			total += 1;
		}

	}

	cout << total; 








}
