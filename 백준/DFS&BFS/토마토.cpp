#include <iostream>
#include <queue>

using namespace std;

int M, N;
int tomato[1001][1001];
int check[1001][1001] = { 0 };
queue<pair<int, int>> q;

int dir[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };

bool isInside(int x, int y) {
	if ((0 <= x) && (x < N) && (0 <= y) && (y < M)) {
		return true;
	}
	else {
		return false;
	}

}



void bfs(int x, int y) {


	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int dy = x + dir[i][0];
			int dx = y + dir[i][1];

			if (isInside(dy, dx) && check[dy][dx] == 0 && tomato[dy][dx] == 0) {
				check[dy][dx] = check[x][y] + 1;
				tomato[dy][dx] = 1;
				q.push(make_pair(dy, dx));
			}
		}


	}



}




int main() {

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
		}
	}

	int ripentomato = 0; 

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 1 || tomato[i][j] == -1) {
				ripentomato++;
			}
		}
	}

	if (ripentomato == (M * N)) {
		cout << 0;
		return 0; 
	}



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	bfs(0, 0);

	int cannot = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 0) {
				cannot++;
			}
		}
	}


	if (cannot >= 1) {
		cout << -1;
		return 0;
	}
    
	int max = check[0][0];
	int maxIndexX = 0;
	int maxIndexY = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (max < check[i][j]) {
				max = check[i][j];
				maxIndexX = i;
				maxIndexY = j;
			}
		}
	}

	cout << max;
	return 0; 

}
