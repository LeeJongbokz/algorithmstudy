#include <iostream>
#include <string>

using namespace std;

char board[5][5];
int direction = 8;

const int dy[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dx[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

bool isInside(int y, int x) {
	if (0 <= y && y < 5 && 0 <= x && x < 5) {
		return true;
	}
	else {
		return false;
	}
}


bool hasWord(int y, int x, const string& word) {

	if (!isInside(y,x)) {
		return false;
	}

	if (board[y][x] != word[0]) {
		return false;
	}

	if (word.length() == 1) {
		return true;
	}

	for (int direction = 0; direction < 8; direction++) {
		int nextY = y + dy[direction];
		int nextX = x + dx[direction];

		if (hasWord(nextY, nextX, word.substr(1))) {
			return true;
		}
	}

	return false;


}



int main() {

	for (int i = 0; i < 5; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < 5; j++) {
			board[i][j] = str[j];
		}

	}

	string input;
	cin >> input;

	bool isExist = hasWord(2, 2, input);

	if (isExist) {
		cout << input << "이 존재합니다." << '\n';
	}
	else {
		cout << input << "이 존재하지 않습니다" << '\n';
	}




}
