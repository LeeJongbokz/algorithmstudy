// 이 문제는 구현 문제임

// 이 문제에서는 특히 2차원 벡터의 활용법에 대해서 많이 배웠음
// 2차원 벡터 v가 있다면, v.erase(v.begin())로 첫번째 벡터값을 제거할 수 있으며,
// v.erase(v.begin()+i) 로 i번째 벡터값을 제거할 수 있음 
// v.insert(v.begin(), make_pair(x,y))로 벡터의 첫번째 위치에 (x,y) 좌표를 넣어줄 수 있음
// 벡터의 insert메소드와 erase메소드를 잘 사용하면, 벡터를 활용하는데 매우 유용함 

#include <iostream>
#include <vector>

using namespace std;

int result = 0; 
int N, K;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isRange(int x, int y) {
	if (1 <= x && x <= N && 1 <= y && y <= N) {
		return true;
	}
	else {
		return false; 
	}
}

vector<pair<int, int>> snake;
vector<pair<int, int>> apple;
vector<pair<int, char>> directionChange;

// dfs 함수에는 재귀함수이면서 dfs탐색을 구현함
// dfs 함수에는 4가지 매개변수가 있음
// x,y는 뱀의 머리가 현재 위치한 좌표를 나타냄
// direction은 뱀의 현재 방향을 나타냄
// time은 snake의 게임의 현재 시간을 나타냄

// x,y가 필요한 이유는 x,y와 방향을 기준으로 다음 이동할 좌표를 정하고,
// 그 좌표에 사과가 있는지 없는지 판단해줘야 하기 때문임

// direction이 필요한 이유는 뱀의 머리가 나아가야 하는 방향에 따라,
// 다음 좌표(nx,ny)를 다르게 지정해줘야 하기 때문임

// time이 필요한 이유는, 게임이 진행된 시간을 측정하면서,
// 게임이 끝난 시점에 결과값을 저장해줘야 하기 때문임 
void dfs(int x, int y, int direction, int time) {

	// 벽에 부딪히면 게임이 끝남 
	if(!isRange(x, y)){
		result = time;
		return;
	}

	// directionChange는 뱀의 방향 변환 정보(시간, 방향)를 저장한 벡터임
	// 여기서 directionChange에는 시간 정보가 오름차순으로 정렬되어 있음
	// 그리고 directionChange[0].second의 방향에 따라 방향을 바꿔줌 
	if (directionChange.size() != 0) {
		
		// time과 directionChange[0].first값과 일치할 때,
		if (time == directionChange[0].first) {
			// directionChange[0].second == 'D'라면
			// direction을 다음과 같이 바꿔줌 
			if (directionChange[0].second == 'D') {
				if (direction == 3) {
					direction = 0;
				}
				else {
					direction += 1;
				}
			}
			// directionChange[0].second == 'L'이라면, direction을 다음과 같이 바꿔줌 
			else if (directionChange[0].second == 'L') {
				if (direction == 0) {
					direction = 3;
				}
				else {
					direction -= 1;
				}
			}

			// directionChange[0]은 이제 불필요해졌으므로, 벡터에서 제거함 
			directionChange.erase(directionChange.begin());

		}
	}


	// 변수 nx,ny는 다음 좌표를 나타냄
	// 다음 좌표는 현재 좌표(x,y)와 방향(direction)을 통해 계산할 수 있음
	int nx = x + dx[direction];
	int ny = y + dy[direction];

	bool isApple = false;

	
	// 다음 좌표(nx,ny)와 일치하는 사과가 있는지를 검사함
	for (int i = 0; i < apple.size(); i++) {
		// 일치하는 사과가 있으면,
		if (nx == apple[i].first && ny == apple[i].second) {
			// isApple을 true로 바꿔줌
			// 이것은 반드시 필요한 코드는 아님. 다만 직관적인 편의를 위해 넣어둠
			isApple = true;
			
			// 해당 위치의 사과를 apple 벡터에서 제거해줌 
			// 뱀이 같은 위치의 사과를 2번 먹는 것을 막기 위해서는
			// 반드시 apple 벡터에서 제거를 해줘야 함 
			apple.erase(apple.begin() + i);
			
			// snake의 머리 부분(snake[0])에 해당 좌표(nx,ny)를 추가함
			// 머리 부분에 해당 좌표를 추가하는 이유는 뱀이 사과를 먹으면서,
			// 그 위치가 뱀의 머리가 되기 때문임 
			snake.insert(snake.begin(), make_pair(nx, ny));
			
	                // 재귀함수를 매개변수 time을 1만큼 늘려서 다시 실행해줌 
			dfs(nx, ny, direction, time + 1);
		}
		else {
			continue;
		}
	}

	// 만약 다음 좌표(nx,ny)에 사과가 존재하지 않는다면,
	if (isApple == false) {
		
		// 우선, 다음 좌표(nx,ny)를 벡터 snake의 머리 부분에 넣어줌 
		snake.insert(snake.begin(), make_pair(nx, ny));

		// 그 다음 뱀이 자기 자신의 몸과 부딪히는지를 확인함
		// 이를 위해서는 새로 추가된 뱀의 머리 좌표(nx,ny)가
		// 기존의 뱀의 좌표(snake[1], snake[2], ...) 와 일치하는지를 확인함
		// 만약 일치한다면 다음 시간(time+1)에 게임이 끝나므로,
		// result에 time+1을 넣어줌 
		
		// 문제를 처음 풀 때는,
		// 이 검사(뱀이 자기 자신의 몸과 부딪히는지)를 dfs 함수의 맨 앞에 뒀었음
		// 이렇게 하니까 발생하는 문제는 snake.pop_back()을 하고 나서 검사를 하기 때문에
		// 머리와 꼬리가 일치하는 경우를 검사할 수 없는 문제가 발생함 
		
		// 따라서 이 단계에서 검사를 해주고 나서,
		// 만약 뱀이 자기 자신의 몸과 부딪힌다면 다음 시간(time+1)에 게임이 끝나므로
		// result에 time+1을 넣고 리턴을 해줌
		for (int i = 1; i < snake.size(); i++) {
			if (nx == snake[i].first && ny == snake[i].second) {
				result = time+1;
				return;
			}
		}

		// 뱀이 사과를 먹지 않았으므로, 꼬리를 제거해줌
		// 뱀이 사과를 먹지 않으면, 길이가 그대로여야 하므로,
		// 머리에 (nx,ny)를 추가해준만큼, 꼬리를 pop_back()해줌 
		snake.pop_back();
		
		// dfs 재귀함수를 실행함 
		dfs(nx, ny, direction, time + 1);
	}


}




int main() {

	int map[110][110];

	// 처음에 주어지는 보드의 크기 N과 사과의 개수 K를 저장함
	cin >> N >> K;

	// K개의 사과에 대한 행(row)값과 열(col)값을 받고,
	// 그것을 apple이라는 2차원 벡터에 저장함
	for (int i = 1; i <= K; i++) {
		int row, col;
		cin >> row >> col;
		apple.push_back(make_pair(row, col));
	}

	// 뱀의 방향 변환 횟수 L을 저장함
	int L;
	cin >> L;

	// L번의 방향 변환에 관한 정보를 저장함 
	// 이 때, directionChange라는 2차원 벡터를 저장함 
	for (int i = 1; i <= L; i++) {
		int x;
		char c;
		cin >> x >> c;
		directionChange.push_back(make_pair(x, c));
	}

	// snake라는 2차원 벡터에 게임의 시작점인 (1,1)을 저장함 
	// snake에는 snake[0], snake[1], snake[2] .. 이런 순으로 뱀의 좌표가 저장되며,
	// 이 중 snake[0]이 뱀의 머리에 해당함
	snake.push_back(make_pair(1, 1));

	// dfs함수에 진입함 
	dfs(1, 1, 1, 0);

	// 결과값인 result를 출력함 
	cout << result; 



}
