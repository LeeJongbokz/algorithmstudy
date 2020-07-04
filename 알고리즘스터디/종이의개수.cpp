#include <iostream>
#include <cstring> 

using namespace std;


int map[3000][3000];
int cnt[10] = { 0 };

// 해당 범위에서 값들이 모두 같은지 확인함
bool isSame(int x, int y, int N) {
	
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (map[x][y] != map[i][j]) {
				return false;
			}
		}
	}

	return true;

}

void recursive(int x, int y, int N) {

  // 해당 범위에서 값들이 모두 같은지 확인함
  // 값이 같을 때, 해당 값을 추가해줌
	if (isSame(x, y, N)) {
		cnt[map[x][y] + 1] += 1;
		return; 
	}

  // 길이를 3등분함
	int M = N / 3;
 
  // 3등분한 길이를 분할 정복(재귀)해나감
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			recursive(x + M * i, y + M * j, M);
		}
	}

}

int main() {


	int N;
	cin >> N;

  // cnt를 초기화함
	memset(cnt, 0, sizeof(cnt));

  // map을 초기화함
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

  // 재귀 함수를 호출함
	recursive(1, 1, N);

  // 결과를 출력함
	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << '\n';
	}

}
