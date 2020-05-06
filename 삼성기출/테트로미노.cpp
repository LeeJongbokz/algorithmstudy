#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 9999999;

int N, M;
int map[510][510];
bool check[510][510];

int maxSum = -INF;

bool isRange(int x, int y) {
	if (1 <= x && x <= N && 1 <= y && y <= M) {
		return true;
	}
	else {
		return false; 
	}
}

int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y, int sum, int cnt) {

	if (cnt == 4) {
		maxSum = max(maxSum, sum);
		return; 
	}

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isRange(nx, ny) && check[nx][ny] == false) {
			check[nx][ny] = true;
			sum += map[nx][ny];
			dfs(nx, ny, sum, cnt + 1);
			sum -= map[nx][ny];
			check[nx][ny] = false; 
		}

	}



}


void dfs2(int x, int y, int sum) {

	vector<int> v;

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isRange(nx, ny)) {
			v.push_back(map[nx][ny]);
		}

	}


	if (v.size() == 2) {
		return;
	}
	else if (v.size() == 3) {
		for (int i = 0; i < 3; i++) {
			sum += v[i];
		}
		

		maxSum = max(maxSum, sum);

	}
	else if (v.size() == 4) {
		sort(v.begin(), v.end(), greater<int>());

		for (int i = 0; i < 3; i++) {
			sum += v[i];
		}
		
		maxSum = max(maxSum, sum);

	}


	return; 



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
			int sum = map[i][j];
			int cnt = 1;
			check[i][j] = true;
			dfs(i, j, sum, cnt);
			check[i][j] = false;
			
			dfs2(i, j, sum);
		}
	}


	cout << maxSum;


}
