#include <iostream>
#include <vector>

using namespace std;

int h, w;
int map[50][50];
bool check[50][50] = { 0 };

int dir[8][2] = { {-1,0}, {1,0}, {0,-1}, {0,1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

bool isInside(int x, int y) {
	if ((0 <= x) && (x < h) && (0 <= y) && (y < w)) {
		return true;
	}
	else {
		return false;
	}
}

void dfs(int x, int y) {

	check[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int dy = x + dir[i][0];
		int dx = y + dir[i][1];

		if (isInside(dy, dx) == true && map[dy][dx] == 1 && check[dy][dx] == false) {
			dfs(dy, dx);
		}
	}

}





int main() {

	while (1) {

		int cnt = 0; 

		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				check[i][j] = false;
				map[i][j] = 0;
			}
		}


		cin >> w >> h;

		if (h == 0 && w == 0) {
			break;
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && check[i][j] == false) {
					dfs(i, j);
					cnt++;
				}
			}
		}


		cout << cnt << '\n';

	}
}




