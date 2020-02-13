#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 10;

int N, M;
int map[MAX][MAX];
bool check[MAX][MAX];
int tempMap[MAX][MAX];
int maxSize = 0; 

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool isInside(int x, int y) {
	if (1 <= x && x <= N && 1 <= y && y <= M) {
		return true;
	}
	else {
		return false;
	}
}

void dfs(int x, int y) {

	tempMap[x][y] = 2;
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (check[nx][ny] == false && tempMap[nx][ny] == 0 && isInside(nx, ny)) {
			dfs(nx, ny);
		}

	}

}


void virusSpread() {

	memset(check, false, sizeof(check));
	memset(tempMap, 0, sizeof(tempMap));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tempMap[i][j] = map[i][j];
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (tempMap[i][j] == 2) {
				dfs(i, j);
			}
		}
	}

	int cnt = 0; 

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (tempMap[i][j] == 0) {
				cnt += 1;
			}
		}
	}


	maxSize = max(maxSize, cnt);



}


void makeWall(int cnt) {
	if (cnt == 3) {
		virusSpread();
		return;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				makeWall(cnt + 1);
				map[i][j] = 0;
			}
		}
	}



}



int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	makeWall(0);

	cout << maxSize; 


}
