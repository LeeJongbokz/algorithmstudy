#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX = 110;

int R = 0;
int C = 0;

int r, c, k;
int map[MAX][MAX];
int numCnt[MAX];
int temp[MAX];
int tempMap[MAX][MAX];
int timeCnt = 0;

vector<pair<int, int>> v;

// 정렬을 한다.
// 갯수가 작은 것을 앞으로 보내준다. 

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second < b.second) {
		return true;
	}
	else if (a.second == b.second) {
		if (a.first < b.first) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}


int main() {

	cin >> r >> c >> k;

	memset(map, 0, sizeof(map));

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}

	R = 3;
	C = 3;



	while (1) {


		if (map[r][c] == k) {
			break;
		}

		timeCnt += 1;

		if (timeCnt >= 101) {
			timeCnt = -1;
			break;
		}

		


		if (R >= C) {

			int maxCol = -INF;

			memset(tempMap, 0, sizeof(tempMap));

			for (int i = 1; i <= R; i++) {

				memset(numCnt, 0, sizeof(numCnt));
				memset(temp, 0, sizeof(temp));

				v.clear();

				for (int j = 1; j <= C; j++) {
					if (map[i][j] == 0) {
						continue;
					}
					else {
						numCnt[map[i][j]] += 1;
					}
				}




				for (int j = 1; j <= 100; j++) {

					if (numCnt[j] == 0) {
						continue;
					}
					else {
						v.push_back(make_pair(j, numCnt[j]));
					}
				}

				sort(v.begin(), v.end(), cmp);


				int index = 1;


				for (int j = 0; j < v.size(); j++) {
					int a = v[j].first;
					int b = v[j].second;
					temp[index++] = a;
					temp[index++] = b;
				}

				index -= 1;

				if (index > 100) {
					index = 100;
				}

				for (int j = 1; j <= index; j++) {
					tempMap[i][j] = temp[j];
				}

				if (maxCol < index) {
					maxCol = index;
				}


			}

			C = maxCol;


			for (int i = 1; i <= R; i++) {
				for (int j = 1; j <= C; j++) {
					map[i][j] = tempMap[i][j];
				}
			}


		}
		else {
		
		
			int maxRow = -INF;

			memset(tempMap, 0, sizeof(tempMap));

			for (int j = 1; j <= C; j++) {

				memset(numCnt, 0, sizeof(numCnt));
				memset(temp, 0, sizeof(temp));

				// 벡터 초기화 
				v.clear();

				// 특정 행에 대해서
				for (int i = 1; i <= R; i++) {
					if (map[i][j] == 0) {
						continue;
					}
					else {
						numCnt[map[i][j]] += 1;
					}
				}


				for (int i = 1; i <= 100; i++) {

					if (numCnt[i] == 0) {
						continue;
					}
					else {
						v.push_back(make_pair(i, numCnt[i]));
					}
				}

				sort(v.begin(), v.end(), cmp);


				int index = 1;


				for (int i = 0; i < v.size(); i++) {
					int a = v[i].first;
					int b = v[i].second;
					temp[index++] = a;
					temp[index++] = b;
				}

				index -= 1;

				if (index > 100) {
					index = 100;
				}

				for (int i = 1; i <= index; i++) {
					tempMap[i][j] = temp[i];
				}

				if (maxRow < index) {
					maxRow = index;
				}


			}

			R = maxRow;


			for (int i = 1; i <= R; i++) {
				for (int j = 1; j <= C; j++) {
					map[i][j] = tempMap[i][j];
				}
			}		
	
		
		}


	}


	cout << timeCnt;



}
