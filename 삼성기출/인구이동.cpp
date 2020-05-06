#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int N, L, R;

int map[100][100];
int unionMap[100][100];
bool check[100][100];

int unionNum = 0;
int unionSum = 0;
int unionMean = 0;
int cnt = 0;
int moveCnt = 0;

vector<pair<int, int>> v;

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

	// dfs로 탐색하면서
	// 전체 수를 카운트(cnt) 하고
	// 방문한 점은 true로 체크하고
	// 해당 위치에 unionNum을 표시한다. 
	// 재귀함수는 최대 맵의 크기, 즉 O(N2)만큼 실행될 수 있다. 

	cnt += 1;
	unionSum += map[x][y];
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];

		int diff = abs(map[x][y] - map[dx][dy]);

		if (isInside(dx, dy) && check[dx][dy] == false && L<=diff && diff <=R) {
			v.push_back(make_pair(dx, dy));
			dfs(dx, dy);
		}
	}

}


int main() {

	cin >> N >> L >> R;

	// O(N2)으로 입력 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}


	// while문은 최대 2000번 실행될 수 있다. 
	while (1) {


		// borderOpen, check, unionMap 초기화 
		memset(check, false, sizeof(check));

		// 같은 연합끼리 숫자를 매기기 위하여, 
		// unionNum이라는 변수를 활용한다. 
		unionNum = 0;

		// O(N2)으로 입력 
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// 해당 위치를 방문한적이 없다면
				if (check[i][j] == false) {
					unionSum = 0;
					unionNum += 1;
					cnt = 0;
					unionMean = 0;

					v.clear();
					v.push_back(make_pair(i, j));
					// dfs로 탐색한다
					dfs(i, j);

					// 합을 전체 수로 나눠준다. 
					unionMean = unionSum / cnt;

					for (int i = 0; i < v.size(); i++) {
						map[v[i].first][v[i].second] = unionMean;
					}
					
				}
			}
		}

		if (1 <= unionNum && unionNum < N*N) {
			moveCnt += 1;
		}else if (unionNum == N * N) {
			break;
		}


	}
	
	// 즉, 위에는 while문 내에서 2중 for문 내에서 
	// 재귀문이 실행된다.
	// 이는 2000*O(N2)*O(N2)번 실행되므로
	// 200O*(N4)번 실행된다
	// 이를 계산하면 약 125억번이 된다. 
	// 그래서 시간 초과가 발생하는 것이다.
	// 이를 예방하려면 적절한 pruning이 필요하다.
	// 

	cout << moveCnt;




}
