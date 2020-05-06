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

void dfs(int x, int y, int direction, int time) {


	if(!isRange(x, y)){
		result = time;
		return;
	}


	if (directionChange.size() != 0) {
		if (time == directionChange[0].first) {
			if (directionChange[0].second == 'D') {
				if (direction == 3) {
					direction = 0;
				}
				else {
					direction += 1;
				}
			}
			else if (directionChange[0].second == 'L') {
				if (direction == 0) {
					direction = 3;
				}
				else {
					direction -= 1;
				}
			}

			directionChange.erase(directionChange.begin());

		}
	}




	int nx = x + dx[direction];
	int ny = y + dy[direction];

	bool isApple = false;

	for (int i = 0; i < apple.size(); i++) {
		if (nx == apple[i].first && ny == apple[i].second) {
			isApple = true;
			apple.erase(apple.begin() + i);
			snake.insert(snake.begin(), make_pair(nx, ny));
			dfs(nx, ny, direction, time + 1);
		}
		else {
			continue;
		}
	}

	if (isApple == false) {
		snake.insert(snake.begin(), make_pair(nx, ny));

		for (int i = 1; i < snake.size(); i++) {
			if (nx == snake[i].first && ny == snake[i].second) {
				result = time+1;
				return;
			}
		}

		snake.pop_back();
		dfs(nx, ny, direction, time + 1);
	}




}




int main() {


	int map[110][110];

	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		int row, col;
		cin >> row >> col;
		apple.push_back(make_pair(row, col));
	}

	int L;
	cin >> L;

	for (int i = 1; i <= L; i++) {
		int x;
		char c;
		cin >> x >> c;
		directionChange.push_back(make_pair(x, c));
	}


	snake.push_back(make_pair(1, 1));

	dfs(1, 1, 1, 0);


	cout << result; 




}
