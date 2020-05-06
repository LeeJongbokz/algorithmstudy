#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int isSquare = 0; 

bool isRange(int x, int y) {
	if (0 <= x && x <= 100 && 0 <= y && y <= 100) {
		return true;
	}
	else {
		return false; 
	}
}

bool visited[110][110];


int isVisited() {

	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (visited[i][j] == true && visited[i + 1][j] == true && visited[i][j + 1] == true && visited[i + 1][j + 1] == true) {
				isSquare += 1;
			}
		}
	}

	return isSquare; 

}

void dfs(int x, int y, int cnt, int generation, vector<pair<int, int>>& v) {

	int nx, ny;
	nx = x;
	ny = y; 
	vector<pair<int, int>> temp;

	if (cnt == 0) {

		nx += v[0].first;
		ny += v[0].second;

		if (isRange(nx, ny)) {
			visited[nx][ny] = true;
		}

	}else if (cnt >= 1) {
		for (int i = v.size() - 1; i >= 0; i--) {

			if (v[i].first == 1 && v[i].second == 0) {
				nx += 0;
				ny += (-1);
				temp.push_back(make_pair(0, -1));
			}
			else if (v[i].first == 0 && v[i].second == -1) {
				nx += (-1);
				ny += 0;
				temp.push_back(make_pair(-1, 0));
			}
			else if (v[i].first == -1 && v[i].second == 0) {
				nx += 0;
				ny += 1;
				temp.push_back(make_pair(0, 1));
			}
			else if (v[i].first == 0 && v[i].second == 1) {
				nx += 1;
				ny += 0;
				temp.push_back(make_pair(1, 0));
			}

			if (isRange(nx, ny)) {
				visited[nx][ny] = true;
			}
			else {
				return;
			}

		}

		for (int i = 0; i < temp.size(); i++) {
			v.push_back(make_pair(temp[i].first, temp[i].second));
		}
	}

	if (cnt == generation) {
		return;
	}

	dfs(nx, ny, cnt + 1, generation, v);





}


int main() {

	int N;
	cin >> N;

	memset(visited, false, sizeof(visited));


	for (int i = 1; i <= N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		visited[x][y] = true;

		vector<pair<int, int>> v;

		if (d == 0) {
			v.push_back(make_pair(1, 0));
		}
		else if (d == 1) {
			v.push_back(make_pair(0, -1));
		}
		else if (d == 2) {
			v.push_back(make_pair(-1, 0));
		}
		else if (d == 3) {
			v.push_back(make_pair(0, 1));
		}

		dfs(x, y, 0, g, v);

	}


	int result = isVisited();

	cout << result;




}
