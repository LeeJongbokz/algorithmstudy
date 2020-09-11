#include <iostream>

using namespace std;

int map[30][30];
int cache[30][30];
int N;

bool isRange(int x, int y) {
	if (1 <= x && x <= N && 1 <= y && y <= N) {
		return true;
	}
	else {
		return false; 
	}
}

int jump(int x, int y) {

	if (!isRange(x, y)) {
		return 0;
	}

	if (x == N && y == N) {
		return 1; 
	}

	int num = map[x][y];


	if (cache[x][y] != -1) {
		return cache[x][y];
	}

	return cache[x][y] = (jump(x + num, y) || jump(x, y + num));


}

int main() {

	memset(cache, -1, sizeof(cache));

	cin >> N;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	int result = jump(1, 1);

	if (result) {
		cout << "도착 가능";
	}
	else {
		cout << "도착 불가능";
	}
}
