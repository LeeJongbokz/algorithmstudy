#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int clock[10][10];
bool visited[10];

void dfs(int num, int direction) {

	visited[num] = true;

	if (num <= 3 && visited[num + 1] == false && clock[num][3] != clock[num+1][7]) {

		if (direction == 1) {
			dfs(num + 1, -1);
		}
		else {
			dfs(num + 1, 1);
		}
	}


	if (num >= 2 && visited[num - 1] == false && clock[num][7] != clock[num - 1][3]) {

		if (direction == 1) {
			dfs(num - 1, -1);
		}
		else {
			dfs(num - 1, 1);
		}
		
	}


	if (direction == 1) {

		int temp = clock[num][8];

		for (int i = 7; i >= 1; i--) {
			clock[num][i + 1] = clock[num][i];
		}
		clock[num][1] = temp;
	}
	else {

		int temp = clock[num][1];

		for (int i = 2; i <= 8; i++) {
			clock[num][i-1] = clock[num][i];
		}

		clock[num][8] = temp;

	}



}



int main() {

	for (int i = 1; i <= 4; i++) {
		string str;
		cin >> str;

		for (int j = 1; j <= 8; j++) {
			clock[i][j] = str[j-1] - '0';
		}
	}

	int K;
	cin >> K;

	while (K--) {

		memset(visited, false, sizeof(visited));

		int num, direction;
		cin >> num >> direction;
		dfs(num, direction);
	}

	int point = 0; 


	for (int i = 1; i <= 4; i++) {
		if (clock[i][1] == 1) {
			point += pow(2, i - 1);
		}
	}

	cout << point;

}
