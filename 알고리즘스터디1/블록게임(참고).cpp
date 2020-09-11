#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<map>
#include<cstring>
#include<cmath>

#define SIZE 110
const int INF = 2e9;

using namespace std;

typedef long long int ll;

int EMPTY = 0;
int BLOCK = 222;

int b_size;

int garo(int x, int y, vector<vector<int>> &board) {
	map<int, int > m; int cnt = 0;
	if (x <= b_size - 2 && y <= b_size - 3) {
		// 0 0 0
		// 0 0 0  탐색
		for (int i = y; i < y + 3; i++) {
			m[board[x][i]]++;
			m[board[x + 1][i]]++;
		}



		if (m[BLOCK] == 2 && m.size() == 2 && m.begin()->first != 0) {
			cnt++;
			for (int j = y; j < y + 3; j++) {
				for (int i = 0; i < b_size; i++) {
					if (board[i][j] == m.begin()->first || board[i][j] == EMPTY || board[i][j] == BLOCK)
						board[i][j] = BLOCK;
					else
						break;
				}
			}
		}
	}
	return cnt;
}
bool sero(int x, int y ,vector<vector<int>> &board) {
	map<int, int> m;	int cnt = 0;
	if (x <= b_size - 3 && y <= b_size - 2) {
		// 0 0
		// 0 0
		// 0 0 탐색
		for (int i = x; i < x + 3; i++) {
			m[board[i][y]]++;
			m[board[i][y + 1]]++;
		}


	
		if (m[BLOCK] == 2 && m.size() == 2 && m.begin()->first != 0) {
			cnt++;
			for (int j = y; j < y + 2; j++) {
				for (int i = 0; i < b_size; i++) {
					if (board[i][j] == m.begin()->first || board[i][j] == EMPTY || board[i][j] == BLOCK)
						board[i][j] = BLOCK;
					else
						break;
				}
			}
		}
	}
	return cnt;
}

int solution(vector<vector<int>> board) {
	b_size = board.size();
	
	
	vector<vector<int>> board;
    vector<int>temp;
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    board.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    board.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    board.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    board.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(4);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    board.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(4);
    temp.push_back(4);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    board.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(3);
    temp.push_back(0);
    temp.push_back(4);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    board.push_back(temp);
    temp.clear();
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(5);
    temp.push_back(5);
    board.push_back(temp);
    temp.clear();
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(2);
    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(3);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(5);
    board.push_back(temp);
    temp.clear();
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(5);
    board.push_back(temp);
    temp.clear();

	
	
	
	for (int j = 0; j < b_size; j++) {
		for (int i = 0; i < b_size; i++) {
        	//맨 위부터 놓여진 블록을 만날때까지 위에서 새로운 블록을 놓음
			board[i][j] = board[i][j] == EMPTY ? BLOCK : board[i][j];
			if (board[i][j] != BLOCK)
				break;
		}
	}

	int res = 0;
	for (int i = 0; i < b_size; i++) {
    	//놓여진 블록이 겹쳐 있을수 있기 때문에 2번 탐색 실시
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < b_size; j++) {
				res += garo(i, j, board);
				res += sero(i, j, board);
			}
		}
	}
	
	return res;
}
