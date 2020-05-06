#include <iostream>
#include <cstring> 

using namespace std;

const int MAX = 60;

int R, C, T;
int map[MAX][MAX];
int tempMap[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool airFresher[MAX][2];
int dustSum = 0;

void calculate() {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] > 0) {
				dustSum += map[i][j];
			}
		}
	}
}


void airFresherLocation() {

	for (int i = 1; i <= R; i++) {
		if (map[i][1] == -1) {
			airFresher[i][1] = true;
		}
	}

}



void update() {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j] += tempMap[i][j];
		}
	}

}

void updateMove(int upper, int under) {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (2 <= i && i <= upper - 1 && 2 <= j && j <= C - 1) {
				continue;
			}
			else if (under + 1 <= i && i <= R - 1 && 2 <= j && j <= C - 1) {
				continue;
			}
			else if ((i == upper || i == under) && j == 1) {
				continue;
			}
			else {
				map[i][j] = tempMap[i][j];
			}
		}
	}
}



void diffuse(int x, int y) {

	int num = map[x][y] / 5;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] != -1 && 1 <= nx && nx <= R && 1 <= ny && ny <= C) {
			map[x][y] -= num;
			tempMap[nx][ny] += num;
		}
	}


}

void dustMoveUpper(int x) {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (i == x && 2<= j && j<=C-1) {
				tempMap[i][j + 1] = map[i][j];
			}
			else if (2 <= i && i <= x && j == C) {
				tempMap[i - 1][j] = map[i][j];
			}
			else if (i == 1 && 2 <= j && j <= C) {
				tempMap[i][j-1] = map[i][j];
			}
			else if (1 <= i && i <= x - 2 && j == 1) {
				tempMap[i+1][j] = map[i][j];
			}
		}
	}


}


void dustMoveUnder(int x) {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (i == x && 2 <= j && j <= C - 1) {
				tempMap[i][j + 1] = map[i][j];
			}
			else if (x <= i && i <= R - 1 && j == C) {
				tempMap[i + 1][j] = map[i][j];
			}
			else if (i == R && 2 <= j && j <= C) {
				tempMap[i][j-1] = map[i][j];
			}
			else if (x + 2 <= i && i <= R && j == 1) {
				tempMap[i - 1][j] = map[i][j];
			}
		}
	}



}


void dfs(int time) {

	if (time == T) {
		calculate();
		return;
	}


	memset(tempMap, 0, sizeof(tempMap));

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] > 0) {
				diffuse(i, j);
			}
		}
	}

	update();

	memset(tempMap, 0, sizeof(tempMap));

	int cnt = 0;
	int upper = 0;
	int under = 0; 

	for (int i = 1; i <= R; i++) {
		if (airFresher[i][1] == 1 && cnt == 0) {
			dustMoveUpper(i);
			upper = i;
			cnt += 1;
		}
		else if (airFresher[i][1] == 1 && cnt == 1) {
			dustMoveUnder(i);
			under = i;
			cnt += 1;
			break;
		}
	}

	updateMove(upper, under);

	dfs(time + 1);



}


int main() {

	cin >> R >> C >> T;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}
	}

    memset(airFresher, false, sizeof(airFresher));
    
	airFresherLocation();

	dfs(0);


	cout << dustSum;




}
