#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 9999999;

int N, M;
int map[510][510];
bool check[510][510];

int maxSum = -INF;

// isRange()함수는 (x,y) 좌표가
// 2차원 map배열에 속하는지를 나타냄 
bool isRange(int x, int y) {
	if (1 <= x && x <= N && 1 <= y && y <= M) {
		return true;
	}
	else {
		return false; 
	}
}

// dx배열과 dy배열은 dfs함수에서 네 방향의 좌표를 탐색하기 위해서 쓰임 
int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };


// dfs함수에는 총 4개의 매개 변수가 포함됨
// 여기서 x와 y는 좌표를 나타내며,
// sum은 전체 더해진 값을
// cnt는 전체 계산한 횟수를 나타냄 

// 이 문제의 핵심은 ㅗ를 제외한 네 가지 테트로미노가
// 아래와 같은 dfs탐색으로 접근 가능하다는 것을 이해하는 것임
// 이는 그림을 그려서 나타내보면 더욱 쉽게 이해할 수 있음

// 단, 주의할 점은 isRange()함수를 통해서 
// 새로 이동한 좌표가 map을 벗어나는지 아닌지를 체크해줘야 한다는 것임
void dfs(int x, int y, int sum, int cnt) {

	// 총 4번 계산하면 테트로미노가 만들어짐
	// 이 때, sum값을 최대값인 maxSum과 비교해서
	// 더 크다면 maxSum의 값을 sum으로 대체함
	if (cnt == 4) {
		maxSum = max(maxSum, sum);
		return; 
	}

	// for문을 통해서 4방향에 대해서 탐색을 진행함
	for (int i = 0; i < 4; i++) {

		// 새로 이동하는 좌표는 변수 nx,ny로 지정함
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 변수 nx와 ny가 map에 속하는지,
		// 그리고 bool check배열로 이전에 방문했었는지 여부를 검사함
		// bool check 배열로 검사하는 것은 매우 중요함
		// 왜냐하면 같은 위치를 중복해서 방문하지 않아야,
		// 테트로미노를 만들 수 있기 때문임 
		if (isRange(nx, ny) && check[nx][ny] == false) {
			// 변수 nx, ny가 방문할 수 있는 위치라면
			// 방문을 하고 bool check배열을 true로 처리함
			check[nx][ny] = true;
			
			// 변수 sum은 전체 더해진 값을 나타냄 
			// sum에 방문한 위치의 값인 map[nx][ny]를 더해줌
			sum += map[nx][ny];
			
			// 재귀함수인 dfs에 진입함
			// 이 때, 전체 계산한 횟수를 나타내는 cnt의 값은
			// 1 증가함
			dfs(nx, ny, sum, cnt + 1);
			
			// 재귀함수의 리턴으로 되돌아오면
			// sum에서 방문한 위치의 값인 map[nx][ny]를 다시 제거해줌
			sum -= map[nx][ny];
			// 방문을 취소하기 위해서 bool check배열을 false로 처리함 
			check[nx][ny] = false; 
		}

	}



}

// dfs2함수는 ㅗ모양의 테트로미노를 검사하기 위해서 고안됨
// 이 때, 내가 취한 접근법은 다음과 같음
// (1) 벡터 v에 (x,y)좌표에서 네 방향 중 탐색 가능한 좌표만 더해줌
//     이렇게 하는 이유는 (x,y)가 ㅗ모양의 중심에 해당하는 위치인데,
//     이 위치를 기준으로 map배열안에 속하는 점들만 더해주는 것임
//     이는 최소 2개에서, 최대 4개가 될 수 있음
//     2개는 map의 4개의 꼭지점인 경우는 접근 가능한 좌표가 2개가 되고,
//     3개는 map의 4개의 변(꼭지점 제외)에 대해서는 접근 가능한 좌표가 3개가 됨
//     나머지는 모두 4개에 접근할 수 있음

// (2) 벡터 v를 기준으로 크기가 2라면, ㅗ모양의 테트로미노를 만들 수 없으므로, 리턴을 하고,
//     크기가 3이라면, 세 점을 모두 sum에 더해줌
//     크기가 4라면, 벡터 v에 속한 점들을 내림차순으로 나열하고,
//     그 중에서 앞의 3개만 더해줌
//     이렇게 더해주는 이유는 테트로미노의 '최대값'을 구하는 것이
//     이 문제의 목표이기 때문임 
void dfs2(int x, int y, int sum) {

	vector<int> v;

	// (1)에 대한 로직 
	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isRange(nx, ny)) {
			v.push_back(map[nx][ny]);
		}

	}

        // (2)에 대한 로직
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

	// 종이의 세로 크기 N과 가로 크기 M을 입력함
	cin >> N >> M;

	// N개의 줄에 종이에 쓰여 있는 수를
	// map이라는 2차원 배열에 입력함 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

        // 2차원 배열 map의 각 좌표(i,j) 마다
	// 한 번씩 dfs함수와 dfs2함수를 실행함
	// 이 때, dfs함수는 ㅗ모양을 제외한 나머지 4개의 테트로미노를 만들기 위한 것이고
	// dfs2함수는 ㅗ모양의 테트로미노를 만들기 위한 것임 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			// (i,j)좌표의 값을 변수 sum에 더해줌
			// 이 의미는 (i,j)좌표가 테트로미노의 시작점과 동시에
			// 테트로미노에 속하는 값이기 때문임
			int sum = map[i][j];
			
			// (i,j)좌표를 포함하였으므로, 마찬가지로 cnt를 1로 지정함
			int cnt = 1;
			
			// bool check[i][j]를 true로 해주는 이유는
			// 테트로미노를 위한 dfs탐색시 중복 방문을 하지 않기 위함임 
			check[i][j] = true;
			
			// dfs에는 총 4개의 매개변수가 포함됨
			// 각각의 변수의 의미는 위에서 설명함 
			dfs(i, j, sum, cnt);
			
			// bool check[i][j]를 false로 해주는 이유는
			// (i,j)좌표에서의 테트로미노 탐색이 끝났으므로
			// 다시 false로 바꿔주는 것임
			check[i][j] = false;
			
			// ㅗ모양 테트로미노에 대해서 검사를 함 
			dfs2(i, j, sum);
		}
	}

        // 테트로미노 중 최대값인 maxSum을 출력함 
	cout << maxSum;


}
