// 코드 수정

#include <iostream>

using namespace std;

int N, L;
int map[110][110];
int temp[110][110];

bool isRowCol[110];
bool isPath[110][110];

bool isRange(int x, int y) {
	if (1 <= x && x <= N && 1 <= y && y <= N) {
		return true;
	}
	else {
		return false;
	}
}


void dfsRowCol(int x, int y) {

	if (y == N) {
		isRowCol[x] = true;
		return;
	}

	if (map[x][y] == map[x][y + 1]) {
		dfsRowCol(x, y + 1);
	}
  
  // 오르막길에 대한 코드 
	else if (map[x][y] + 1 == map[x][y + 1]) {

		int length = L;
		int dy = x;
		int dx = y;

		while (length--) {
			if (isPath[dy][dx] == true || !isRange(dy, dx)) {
				isRowCol[x] = false;
				return;
			}

			if (map[x][y] != map[dy][dx]) {
				isRowCol[x] = false;
				return;
			}

			isPath[dy][dx] = true;
			dx -= 1;
		}
		
		dfsRowCol(x, y + 1);


	}
  // 오르막길 조건에 맞지 않을 때
  
	else if (map[x][y] + 1 < map[x][y + 1]) {
		isRowCol[x] = false;
		return;

	}
  
  // 내리막길에 대한 코드 
  
	else if (map[x][y] - 1 == map[x][y + 1]) {

		int length = L;
		int dy = x;
		int dx = y+1;

		while (length--) {
			if (!isRange(dy, dx)) {
				isRowCol[x] = false;
				return;
			}
			if (map[x][y + 1] != map[dy][dx]) {
				isRowCol[x] = false;
				return;
			}

			isPath[dy][dx] = true;
			dx += 1;
		}

		dfsRowCol(x, y + L);

	}
  // 내리막길이 맞지 않을 때 
	else if (map[x][y] - 1 > map[x][y + 1]) {
		isRowCol[x] = false;
		return;
	}

}


int main() {

	cin >> N >> L;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

  // row 검사

	for (int i = 1; i <= N; i++) {
		dfsRowCol(i, 1);
	}

  int cnt = 0; 

	for (int i = 1; i <= N; i++) {
		if (isRowCol[i] == true) {
			cnt += 1;
		}
	}

  // map의 row와 col을 바꿔준다

  for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			temp[i][j] = map[j][i];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = temp[i][j];
		}
	}
  
  
  // col을 검사하기 이전에 isRowcol와 경사로를 초기화.

  for(int i=1; i<=N; i++){
        isRowCol[i] = false;
  }

	
  for (int i = 1; i <= N; i++) {
	for (int j = 1; j <= N; j++) {
		isPath[i][j] = false;
	}
  }
  
  // col 검사
  
  for (int i = 1; i <= N; i++) {
	dfsRowCol(i, 1);
  }


  for (int i = 1; i <= N; i++) {
	if (isRowCol[i] == true) {
		cnt += 1;
	}
  }
 
    
  cout << cnt;

}
