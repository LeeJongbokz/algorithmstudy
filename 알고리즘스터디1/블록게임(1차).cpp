#include <iostream> 
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool check[60][60];
bool isUsed[210];
vector<pair<int, int>> emptySpaces[210];
int total = 0;
int len; 

bool isRange(int x, int y) {
    if (1 <= x && x <= len && 1 <= y && y <= len) {
        return true;
    }
    else {
        return false; 
    }
}

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

vector<vector<int>> board;

bool cmp(pair<int, int>& a, pair<int, int>& b) {

    if (a.second < b.second) {
        return true;
    }
    else if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return false;
    }
}


void getEmptySpace(vector<pair<int, int>>& v) {

    int rowNum = 0;
    int colNum1 = 0;
    int colNum2 = 0;
    int rowCnt = 1;

    int rowNum1 = 0;
    int rowNum2 = 0;
    int colNum = 0;

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i].first == v[i + 1].first) {
            rowCnt += 1;
        }
    }

    if (rowCnt == 3) {

        if (v[0].first == v[1].first) {
            rowNum = v[0].first + 1;
        }
        else {
            rowNum = v[0].first;
        }

        sort(v.begin(), v.end(), cmp);

        if (v[0].second == v[1].second) {
            colNum1 = v[0].second + 1;
            colNum2 = v[0].second + 2;
        }
        else {
            colNum1 = v[0].second;
            colNum2 = v[0].second + 1;
        }

        emptySpaces[total].push_back(make_pair(rowNum, colNum1));
        emptySpaces[total].push_back(make_pair(rowNum, colNum2));
        total += 1;

    }
    else {

        sort(v.begin(), v.end(), cmp);

        if (v[0].second == v[1].second) {
            colNum = v[0].second + 1;
        }
        else {
            colNum = v[0].second;
        }

        sort(v.begin(), v.end());

        if (v[0].first == v[1].first) {
            rowNum1 = v[0].first + 1;
            rowNum2 = v[0].first + 2;
        }
        else {
            rowNum1 = v[0].first;
            rowNum2 = v[0].first + 1;
        }

        emptySpaces[total].push_back(make_pair(rowNum1, colNum));
        emptySpaces[total].push_back(make_pair(rowNum2, colNum));

    }



}

void getEmptySpaces2(vector<pair<int, int>>& v) {

    sort(v.begin(), v.end());

    int rowCnt = 1;

    int rowNum = 0;
    int colNum1 = 0;
    int colNum2 = 0;

    int colNum = 0;
    int rowNum1 = 0;
    int rowNum2 = 0;

    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i].first == v[i].second) {
            rowCnt += 1;
        }
    }

    if (rowCnt == 3) {

        if (v[0].first == v[1].first) {
            rowNum = v[0].first + 1;
        }
        else {
            rowNum = v[0].first;
        }

        sort(v.begin(), v.end(), cmp);

        colNum1 = v[0].second;
        colNum2 = v[3].second;

        emptySpaces[total].push_back(make_pair(rowNum, colNum1));
        emptySpaces[total].push_back(make_pair(rowNum, colNum2));
        total += 1;

    }
    else {

        sort(v.begin(), v.end(), cmp);

        if (v[0].second == v[1].second) {
            colNum = v[0].second + 1;
        }
        else {
            colNum = v[0].second;
        }

        sort(v.begin(), v.end());

        rowNum1 = v[0].first;
        rowNum2 = v[3].first;
        emptySpaces[total].push_back(make_pair(rowNum1, colNum));
        emptySpaces[total].push_back(make_pair(rowNum2, colNum));
    }


}



bool dfs(int x, int y, int cnt, int num, vector<pair<int, int>>& v) {

    if (cnt == 4) {
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (check[nx][ny] == false && board[nx][ny] == num && isRange(nx, ny)) {
            check[nx][ny] = true;
            v.push_back(make_pair(nx, ny));
            return dfs(nx, ny, cnt + 1, num, v);
        }
    }

    return false; 

}

bool isRight(int x, int y, int num, vector<pair<int, int>>& v) {

    int lx = x - 1;
    int ly = y;
    int rx = x + 1;
    int ry = y;
    int nx = x;
    int ny = y - 1;
    int sx = x;
    int sy = y + 1;

    int cnt = 0;

    if (isRange(lx, ly) && board[lx][ly] == num) {
        cnt += 1;
        v.push_back(make_pair(lx, ly));
    }
    if (isRange(rx, ry) && board[rx][ry] == num) {
        cnt += 1;
        v.push_back(make_pair(rx, ry));
    }
    if (isRange(nx, ny) && board[nx][ny] == num) {
        cnt += 1;
        v.push_back(make_pair(nx, ny));
    }
    if (isRange(sx, sy) && board[sx][sy] == num) {
        cnt += 1;
        v.push_back(make_pair(sx, sy));
    }

    if (cnt == 3) {
        return true;
    }
    else {
        return false;
    }

}


int main() {
    int answer = 0;

    memset(check, false, sizeof(check));
    memset(isUsed, false, sizeof(isUsed));

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

    len = board.size();

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (board[i][j] != 0) {
                   vector<pair<int, int>> v;

                   int num = board[i][j];
                   v.push_back(make_pair(i, j));
                   int cnt = 1;
                   check[i][j] = true;
                   bool result = dfs(i, j, cnt, num, v);

                   if (v.size() == 4 && result == true) {
                        getEmptySpace(v);
                        isUsed[num] = true;
                   }

            }
            
        }
    }

    memset(check, false, sizeof(check));

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (board[i][j] != 0 && isUsed[board[i][j]] == false) {
                vector<pair<int, int>> v;
                int num = board[i][j];
                bool result = isRight(i, j, num, v);

                if (result) {
                    getEmptySpaces2(v);
                }
            }
        }
    }





    
}
