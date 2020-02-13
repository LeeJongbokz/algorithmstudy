#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, L, R;

int map[100][100];
bool borderOpen[100][100][100][100];
int unionMap[100][100];
bool check[100][100];

int unionNum = 0;
int unionSum = 0;
double unionMean = 0; 
int cnt = 0; 
int moveCnt = 0; 
int borderOpenCnt = 0;

vector<double> v;

bool isInside(int x, int y) {
	if (1 <= x && x <= N && 1 <= y && y <= N) {
		return true;
	}
	else {
		return false;
	}
}

int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };


void dfs(int x, int y) {

	cnt += 1;
	unionSum += map[x][y];
	check[x][y] = true;
	unionMap[x][y] = unionNum;

	for (int i = 0; i < 4; i++) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];

		if (isInside(dx, dy) && check[dx][dy] == false && (borderOpen[x][y][dx][dy] == true || borderOpen[dx][dy][x][y] == true)) {
			dfs(dx, dy);
		}
	}



}



int main() {

	cin >> N >> L >> R;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}



	while (1) {

		v.clear();
		v.push_back(-1);

		memset(borderOpen, false, sizeof(borderOpen));
		memset(check, false, sizeof(check));
		memset(unionMap, 0, sizeof(unionMap));

		borderOpenCnt = 0; 

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N - 1; j++) {
				int gap = abs(map[i][j] - map[i][j + 1]);
				if (L <= gap && gap <= R) {
					borderOpen[i][j][i][j + 1] = true;
					borderOpen[i][j + 1][i][j] = true;
					borderOpenCnt += 1;
				}
			}
		}

		for (int j = 1; j <= N; j++) {
			for (int i = 1; i <= N - 1; i++) {
				int gap = abs(map[i][j] - map[i + 1][j]);
				if (L <= gap && gap <= R) {
					borderOpen[i][j][i + 1][j] = true;
					borderOpen[i + 1][j][i][j] = true;
					borderOpenCnt += 1;
				}
			}
		}

		if (borderOpenCnt == 0) {
			break;
		}
		else {
			moveCnt += 1;
		}


		unionNum = 0;


		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (check[i][j] == false) {
					unionSum = 0;
					unionNum += 1;
					cnt = 0;
					unionMean = 0; 

					dfs(i, j);

					unionMean = unionSum / cnt;

					v.push_back(floor(unionMean));
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int num = unionMap[i][j];
				map[i][j] = (int)v[num];
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << map[i][j];
			}
			cout << '\n';
		}


	}



	cout << moveCnt; 




}
