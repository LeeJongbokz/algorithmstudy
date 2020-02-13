#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX = 25;
const int INF = 987654321;

int N;
int map[MAX][MAX];
int elect[MAX][MAX];
bool check[MAX][MAX];

int dx[] = {-1, 0, 0, 1, 1, 1 };
int dy[] = {0 , 1, -1, 0, -1,1 };

typedef struct {
	int tx, ty, lx, ly, rx, ry, bx, by;
	int d1, d2;
}vertex;

int areaSum[6]; 
int minGap = INF;


bool init(vertex& v) {

	memset(elect, 0, sizeof(elect));
	memset(check, false, sizeof(check));

	v.lx = v.tx + v.d1;
	v.ly = v.ty - v.d1;

	v.rx = v.tx + v.d2;
	v.ry = v.ty + v.d2;

	v.bx = v.tx + v.d2 + v.d1;
	v.by = v.ty + v.d2 - v.d1;

	if (v.ly < 1 || v.ry > N || v.bx > N) {
		return false;
	}

	return true;

}

void mark(int sX, int sY, int area, int direction, int d) {

	elect[sX][sY] = area;

	int nx = sX;
	int ny = sY;

	for (int i = 1; i <= d; i++) {
		nx += dx[direction];
		ny += dy[direction];
		elect[nx][ny] = area;
	}

}


void mark(int sX, int sY, int area, int direction) {

	int nx = sX + dx[direction];
	int ny = sY + dy[direction];

	while (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
		elect[nx][ny] = area;
		nx += dx[direction];
		ny += dy[direction];
	}
}



void marker(vertex& v) {

	mark(v.tx, v.ty, 5, 4, v.d1);
	mark(v.rx, v.ry, 5, 4, v.d1);
	mark(v.tx, v.ty, 5, 5, v.d2);
	mark(v.lx, v.ly, 5, 5, v.d2);

	mark(v.tx, v.ty, 1, 0);
	mark(v.rx, v.ry, 2, 1);
	mark(v.lx, v.ly, 3, 2);
	mark(v.bx, v.by, 4, 3);
}


void dfs(int x, int y, int area) {

	if (elect[x][y] != 0) {
		return;
	}

	elect[x][y] = area;
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (check[nx][ny] == false && 1 <= nx && nx <= N && 1 <= ny && ny <= N) {
			dfs(nx, ny, area);
		}

	}


}



void calculate() {

	memset(areaSum, 0, sizeof(areaSum));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			areaSum[elect[i][j]] += map[i][j];
		}
	}

	areaSum[5] += areaSum[0];

	int MAXNUM = -INF;
	int MINNUM = INF;

	for (int i = 1; i <= 5; i++) {
		if (MAXNUM < areaSum[i]) {
			MAXNUM = areaSum[i];
		}

		if (MINNUM > areaSum[i]) {
			MINNUM = areaSum[i];
		}
	}

	int gap = MAXNUM - MINNUM;

	minGap = min(minGap, gap);


}


void divideArea(vertex& v) {

	for (int d1 = 1; d1 < N; d1++) {
		for (int d2 = 1; d2 < N; d2++) {
			v.d1 = d1;
			v.d2 = d2;

			if (init(v) == false) {
				continue;
			}

			marker(v);

			dfs(1, 1, 1);
			dfs(1, N, 2);
			dfs(N, 1, 3);
			dfs(N, N, 4);

			calculate();

		}
	}
}



int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			vertex v;

			v.tx = i, v.ty = j;

			divideArea(v);

		}
	}

	cout << minGap;


}
