#include <iostream>
#include <string>

using namespace std;

char map[10][10];

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool hasWord(int x, int y, const string& word) {

	if (map[x][y] != word[0]) {
		return false;
	}

	if (word.size() == 1) {
		return true;
	}

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (1 <= nx && nx <= 5 && 1 <= ny && ny <= 5) {
			hasWord(nx, ny, word.substr(1));
		}
	}


}



int main() {

	for (int i = 1; i <= 5; i++) {
		string hello;
		cin >> hello;
		for (int j = 1; j <= 5; j++) {
			map[i][j] = hello[j-1];
		}
	}

	string findString;
	cin >> findString;

	int isExist = 0; 

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			bool result = hasWord(i, j, findString);
			if (result) {
				isExist += 1;
				break;
			}
			else {
				continue;
			}

		}
		if (isExist == 1) {
			break;
		}
	}

	if (isExist == 1) {
		cout << "존재합니다";
	}
	else {
		cout << "존재하지 않습니다";
	}

}
