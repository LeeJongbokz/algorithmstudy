#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10;
const int INF = 987654321;

int N, M;
int map[MAX][MAX];
int check[MAX][MAX];

vector<int> v1;
vector<pair<int, int>> v2;
int minCnt = INF; 

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


void dfs(int x, int y, int type, int d) {

	if (type == 1) {
		check[x][y] += 1;
	}
	else {
		check[x][y] -= 1;
	}

	x += dx[d];
	y += dy[d];

	if (map[x][y] != 6 && 1 <=x && x <= N && 1 <=y && y<=M) {
		if (type == 1) {
			dfs(x, y, 1, d);
		}
		else {
			dfs(x, y, 0, d);
		}
	}

}



void calculate() {

	int cnt = 0; 

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (check[i][j] == 0) {
				cnt += 1;
			}
		}
	}

	minCnt = min(minCnt, cnt);

}




void recursive(int index) {

	if (index == v1.size()) {
		calculate();
		return;
	}

	int x = v2[index].first;
	int y = v2[index].second;

	if (v1[index] == 1) {

		for (int i = 0; i < 4; i++) {
			dfs(x, y, 1, i);
			recursive(index + 1);
			dfs(x, y, 0, i);
		}
	}
	else if (v1[index] == 2) {

		for (int i = 0; i < 2; i++) {
			dfs(x, y, 1, i);
			dfs(x, y, 1, i + 2);

			recursive(index + 1);

			dfs(x, y, 0, i);
			dfs(x, y, 0, i + 2);
		}

	}
	else if (v1[index] == 3) {

		for (int i = 0; i < 4; i++) {
			dfs(x, y, 1, i);
			if (i == 3) {
				dfs(x, y, 1, 0);
			}
			else {
				dfs(x, y, 1, i + 1);
			}

			recursive(index + 1);

			dfs(x, y, 0, i);

			if (i == 3) {
				dfs(x, y, 0, 0);
			}
			else {
				dfs(x, y, 0, i + 1);
			}
		}
	}
	else if (v1[index] == 4) {

		for (int i = 0; i < 4; i++) {
			dfs(x, y, 1, i);

			if (i == 3) {
				dfs(x, y, 1, 0);
			}
			else {
				dfs(x, y, 1, i + 1);
			}

			if (i == 2) {
				dfs(x, y, 1, 0);
			}
			else if (i == 3) {
				dfs(x, y, 1, 1);
			}
			else {
				dfs(x, y, 1, i + 2);
			}

			recursive(index + 1);
			dfs(x, y, 0, i);

			if (i == 3) {
				dfs(x, y, 0, 0);
			}
			else {
				dfs(x, y, 0, i + 1);
			}

			if (i == 2) {
				dfs(x, y, 0, 0);
			}
			else if (i == 3) {
				dfs(x, y, 0, 1);
			}
			else {
				dfs(x, y, 0, i + 2);
			}

		}
	}
	else if (v1[index] == 5) {

		dfs(x, y, 1, 0);
		dfs(x, y, 1, 1);
		dfs(x, y, 1, 2);
		dfs(x, y, 1, 3);
		recursive(index + 1);
		dfs(x, y, 0, 0);
		dfs(x, y, 0, 1);
		dfs(x, y, 0, 2);
		dfs(x, y, 0, 3);

	}


}


int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 1) {
				v1.push_back(1);
				v2.push_back(make_pair(i, j));
			}else if (map[i][j] == 2) {
				v1.push_back(2);
				v2.push_back(make_pair(i, j));
			}else if (map[i][j] == 3) {
				v1.push_back(3);
				v2.push_back(make_pair(i, j));
			}else if (map[i][j] == 4) {
				v1.push_back(4);
				v2.push_back(make_pair(i, j));
			}else if (map[i][j] == 5) {
				v1.push_back(5);
				v2.push_back(make_pair(i, j));
			}
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 6) {
				check[i][j] = 6;
			}
		}
	}

	recursive(0); 

	cout << minCnt;

}
