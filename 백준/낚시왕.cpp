#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

const int MAX = 110;

int total = 0;
int R, C, M;
int map[MAX][MAX];

typedef struct {
	int x;
	int y;
	int speed;
	int direction;
	int size;
	bool alive;
}Shark;

vector<Shark> v;

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };


void eat_shark() {


	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] >= 2) {

				int max_size = 0;

				for (int k = 0; k < v.size(); k++) {
					if (v[k].x == i && v[k].y == j && v[k].alive == true && max_size < v[k].size) {
						max_size = v[k].size;
					}
				}

				for (int k = 0; k < v.size(); k++) {
					if (v[k].x == i && v[k].y == j && v[k].alive == true && max_size != v[k].size) {
						v[k].alive = false;
					}
				}

				map[i][j] = 1;


			}
		}
	}


}



void move_shark() {


	for (int i = 0; i < v.size(); i++) {

		if (v[i].alive == false) {
			continue;
		}

		int sx = v[i].x;
		int sy = v[i].y;
		int speed = v[i].speed;
		int direction = v[i].direction;

		if (direction == 1 || direction == 2) {
			speed %= 2 * (R - 1);
		}
		else {
			speed %= 2 * (C - 1);
		}

		map[sx][sy] -= 1;


		while (speed--) {

			sx += dx[direction];
			sy += dy[direction];

			if (sx < 1 || sx > R || sy < 1 || sy > C) {
				sx -= dx[direction];
				sy -= dy[direction];
				speed += 1;

				if (direction == 1) {
					direction = 2;
				}
				else if (direction == 2) {
					direction = 1;
				}
				else if (direction == 3) {
					direction = 4;
				}
				else if (direction == 4) {
					direction = 3;
				}

			}

		}

		map[sx][sy] += 1;
		v[i].x = sx;
		v[i].y = sy;
		v[i].direction = direction;



	}







}


void catch_shark(int col) {

	for (int i = 1; i <= R; i++) {

		if (map[i][col] == 0) {
			continue;
		}
		
		for (int j = 0; j < v.size(); j++) {
			if (v[j].alive == false) {
				continue;
			}

			if (v[j].x == i && v[j].y == col && v[j].alive == true) {
					map[i][col] = 0;
					total += v[j].size;
					v[j].alive = false;
					return;
				}
			}
	}

}






int main() {

	cin >> R >> C >> M;

	memset(map, 0, sizeof(map));

	for (int i = 1; i <= M; i++) {
		Shark s;
		cin >> s.x >> s.y >> s.speed >> s.direction >> s.size;

		map[s.x][s.y] = 1;
		s.alive = true;
		v.push_back(s);
	}


	for (int i = 1; i <= C; i++) {
		catch_shark(i);
		move_shark();
		eat_shark();
	}


	cout << total;


}
