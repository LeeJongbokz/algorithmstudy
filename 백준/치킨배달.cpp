#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 50;
const int INF = 987654321;

int N, M;
int map[MAX][MAX];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

bool visited[13];
int result;


int calDistance(pair<int, int> a, pair<int, int> b) {

	return abs(a.first - b.first) + abs(a.second - b.second);

}


void getDistance(int idx, int selected) {


	if (selected == M) {

		int tempResult = 0;

		for (int i = 0; i < house.size(); i++) {

			int minDistance = INF;

			for (int j = 0; j < chicken.size(); j++) {

				if (visited[j]) {
					int distance = calDistance(house[i], chicken[j]);
					minDistance = min(minDistance, distance);
				}
			}

			tempResult += minDistance;
		}

		result = min(result, tempResult);


		return;
	}


	if (idx == chicken.size()) {
		return;
	}

	visited[idx] = true;
	getDistance(idx + 1, selected + 1);

	visited[idx] = false;
	getDistance(idx + 1, selected);

}





int main() {

	cin >> N >> M;


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}

			if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	result = INF;

	getDistance(0, 0);

	cout << result;



}
