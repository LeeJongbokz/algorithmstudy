#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std;

const int INF = 987654321;

int MIN = 4;
int N, M, H;
bool line[31][11];
int minCnt = INF;

void calculate(int cnt) {

	int sN, sH;

	for (int i = 1; i <= N; i++) {

		sH = 1;
		sN = i;

		while (sH <= H) {
			if (line[sH][sN] == true) {
				sN += 1;
			}
			else if (line[sH][sN - 1] == true) {
				sN -= 1;
			}
			sH += 1;
		}

		if(sN != i){
			return;
		}

	}

	minCnt = min(minCnt, cnt);


}


void dfs(int pos, int cnt) {
	
	if (cnt >= 4) {
		return;
	}

	if (pos > H) {
		calculate(cnt);
		return;
	}

	dfs(pos + 1, cnt);

	for (int i = 1; i < N; i++) {
		if (line[pos][i] == true) {
			continue;
		}
		else if (line[pos][i] == false) {
			line[pos][i] = true;
			dfs(pos, cnt + 1);
			line[pos][i] = false;
		}
	}

}





int main() {

	cin >> N >> M >> H;

	memset(line, false, sizeof(line));

	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		line[a][b] = true;
	}


	dfs(0, 0);

	if (minCnt == INF) {
		cout << -1;
	}
	else {
		cout << minCnt;
	}


}

