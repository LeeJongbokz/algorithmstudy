// 이 문제는 구현 문제임 

// 주의할 점은
// (1) 시간 복잡도와 관련된 문제를 해결하는 것
// (2) 여러 변수들을 매우 꼼꼼히 관리하는 것
// (3) 상어와 관련된 정보를 효율적으로 나타내는 것
// (4) 정보의 업데이트를 효과적으로 반영하는 것
// 이 중요함

#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

const int MAX = 110;

int total = 0;
int R, C, M;
int map[MAX][MAX];

// 상어의 정보를 저장할 구조체 Shark를 만들어줌
// 여기에는 상어의 좌표(x,y), 속도(speed), 방향(direction),
// 크기(size), 생존 여부(alive)를 저장함 
typedef struct {
	int x;
	int y;
	int speed;
	int direction;
	int size;
	bool alive;
}Shark;

// 상어를 저장하기 위한 벡터 v를 만듦
// 이 때, 벡터 v의 자료형은 <Shark>로 지정함 
vector<Shark> v;

// dx, dy 배열은 방향을 나타내기 위해서 활용함 
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };

// eat_shark()는 크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는 것을 구현함
void eat_shark() {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			// map[i][j]에 2마리 이상의 상어가 존재할 때, 
			if (map[i][j] >= 2) {

				int max_size = 0;
				
				// 해당 좌표에 있는 상어 중, 가장 크기가 큰 상어의 크기를 
				// max_size에 저장함
				for (int k = 0; k < v.size(); k++) {
					if (v[k].x == i && v[k].y == j && v[k].alive == true && max_size < v[k].size) {
						max_size = v[k].size;
					}
				}

				// 가장 크기가 큰 상어를 제외한 나머지 상어를 모두 alive=false 처리함
				for (int k = 0; k < v.size(); k++) {
					if (v[k].x == i && v[k].y == j && v[k].alive == true && max_size != v[k].size) {
						v[k].alive = false;
					}
				}
				
				// map[i][j]의 크기를 1로 업데이트 함
				// 이는 map[i][j]에 1마리의 상어만이 남았음을 의미함 
				map[i][j] = 1;


			}
		}
	}


}


// move_shark()는 상어의 이동을 구현함 
void move_shark() {

	// 모든 상어에 대하여, 
	for (int i = 0; i < v.size(); i++) {

		// 상어가 죽었다면 이동시킬 필요가 없으므로
		// continue를 함 
		if (v[i].alive == false) {
			continue;
		}
	
		// 상어의 좌표, 속력, 방향을 쉽게 다루기 위해서
		// 각각의 변수를 선언해줌 
		int sx = v[i].x;
		int sy = v[i].y;
		int speed = v[i].speed;
		int direction = v[i].direction;

		// map에서 상어가 위치한 위치의 값을 -1을 해줌
		// 여기서 이것을 0으로 바꾸면 안됨
		// 0으로 바꾸면 안되는 이유는 
		// 현재 상어가 이동 중인데, 이동 중에 하나의 좌표에 
		// 여러 마리의 상어가 존재할 수 있기 때문임
		// 따라서 map[sx][sx]=0이 되면 해당 위치의 상어들이 모두 없어지는 오류가 발생함 
		map[sx][sy] -= 1;
        
		// 이 부분이 매우 중요함
		// 상어의 speed는 최대 1000일 수 있고, 상어의 수는 최대 10000마리임 
		// 따라서 최악의 경우를 가정하면,
		// 100개의 열에 대해, 10000마리의 상어에 대해, 1000번씩 반복문이 실행되면
		// 100x10000x1000 = 1000000000 즉, 10억번이 실행되어야 하므로 
		// 시간 초과가 발생함 
		
		// 즉, 시간 복잡도를 줄일 수 있는 설계를 할 수 있는지를 보고자 하는 것이고,
		// 이 경우는 아래와 같이 speed 값을 줄여서 나타낼 수 있음 
		
		// direction이 1 or 2라는 것은 위 혹은 아래로 움직이는 것을 의미함
		// 이 경우는 speed 를 2*(R-1)로 나눈 값으로 나타낼 수 있음
		// 이렇게 나타낼 수 있는 이유는 
		// 위 혹은 아래로 움직일 때, 상어가 같은 위치에 같은 방향으로 오는데 있어서 
		// 2*(R-1)번이 걸리기 때문임
		
		// 예를 들어 R=4이고, 상어의 처음 위치가 (1,1)이라면,
		// 상어는 (1,1) -> (2,1) -> (3,1) -> (4,1) -> (3,1) -> (2,1) -> (1,1)
		// 즉, 6번의 이동으로 처음 위치로 돌아옴
		// 이는 2*(4-1)과 같음 
		
		// 따라서 speed가 매우 큰 수라 하더라도 
		// 결국은 2*(R-1)마다 제자리로 돌아오므로 
		// 이를 나눈 나머지 값만큼만 이동시켜주면 됨
		
		// 예를 들어, speed가 1000이고, R이 4고, 상어가 (1,1)에 위치했다면,
		// 상어는 6번마다 제자리로 돌아오므로, 
		// 1000 % 6 = 4, 즉 1000번 움직이는 것은 4번 움직이는 것과 같은 효과를 냄   
		// 따라서 speed는 speed %= 2*(R-1)로 나타내어도 무방함 
        	if (direction == 1 || direction == 2) {
			speed %= 2 * (R - 1);
		}
		// 마찬가지로 direction이 3 or 4라는 것은 오른쪽 혹은 왼쪽으로 움직이는 것을 의미함
		// 이 경우도 마찬가지로 모듈로 연산을 적용해줄 수 있음 
		else {
			speed %= 2 * (C - 1);
		}

		// speed만큼 반복문을 순회함 
		while (speed--) {

			// direction의 방향으로 한 칸을 움직임 
			sx += dx[direction];
			sy += dy[direction];

			// 만약 움직이다가 map을 벗어나게 되면
			// 이전에 더한 값을 빼주고 speed를 다시 1만큼 더해줌
			// 이렇게 하는 이유는 map을 벗어나는 경우는 없으며,
			// map의 맨 끝에 부딪히는 경우, 좌표는 그대로인채
			// 방향만 바꿔주기 위함임
			// 즉, 좌표가 그대로임을 나타내기 위해 다시 더한 값을 빼주게 되고
			// speed도 다시 1만큼 더함 
			if (sx < 1 || sx > R || sy < 1 || sy > C) {
				sx -= dx[direction];
				sy -= dy[direction];
				speed += 1;

				// 방향을 바꿔줌
				// 위(1)인 경우는 아래(2)로 
				// 아래(2)인 경우는 위(1)로
				// 오른쪽(3)인 경우는 왼쪽(4)으로
				// 왼쪽(4)인 경우는 오른쪽(3)으로 바꿔줌 
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

		// speed만큼 이동이 끝나면
		// 새로운 위치에 1만큼 값을 더해줌
		// 이는 새로운 위치로 상어가 이동했음을 나타냄 
		map[sx][sy] += 1;
		
		// 그리고 상어가 있는 벡터 v[i]의 좌표값과 방향을 업데이트 함 
		// 이것을 업데이트하는 이유는 이것을 업데이트해야만
		// 이후에 catch_shark(), ear_shark()에서 잘 활용할 수 있기 때문임 
		v[i].x = sx;
		v[i].y = sy;
		v[i].direction = direction;



	}





}

// catch_shark()는 낚시왕이 각 열마다 상어 낚시를 하는 것을 나타내기 위한 함수임 
// 이 때, col값을 매개변수로 전달해주는 이유는
// 함수의 구현에서 이를 정보로 활용하기 때문임 
void catch_shark(int col) {

	// 특정 열의 모든 행에 대하여 검사함
	// 이 때, 1부터 R까지를 검사함
	for (int i = 1; i <= R; i++) {

		// 만약, 상어가 존재하지 않는다면 그냥 continue를 함 
		if (map[i][col] == 0) {
			continue;
		}
		
		// 만약 상어가 존재한다면, 벡터 v에 저장된 상어 중
		// 어떤 상어인지를 검사함 
		// 이렇게 하는 이유는 해당 상어의 사이즈를 전체 잡은 상어 크기의 합에 더해줌과 동시에
		// 상어의 생존 정보를 false로 바꿔주기 위함임 
		for (int j = 0; j < v.size(); j++) {

			// 만약 v에 있는 상어가 죽었다면
			// 그 함수는 해당 상어가 아니므로
			// continue를 함 
			if (v[j].alive == false) {
				continue;
			}

			// 만약 v에 있는 상어가
			// (1)좌표가 일치하면서 
			// (2)살아있는 상어 라면
			if (v[j].x == i && v[j].y == col && v[j].alive == true) {
					// 해당 map의 좌표의 값을 0으로 바꿔줌
					// 이는 해당 위치에 상어가 1마리만 있음을 전제로 함 
					map[i][col] = 0;
				
					// 전체 잡은 상어 크기의 합에 해당 상어의 크기를 더해줌 
					total += v[j].size;
				
					// 상어의 생존 여부를 false로 처리함 
					v[j].alive = false;
				
					// catch_shark()를 바로 끝내 버림
					// 이는 낚시왕이 가장 작은 행에서
					// 1마리의 상어만 잡기 때문임 
					return;
				}
			}
	}

}






int main() {

	// 격자판의 크기에 관한 정보인 R,C와 상어의 수인 M을 저장함
	cin >> R >> C >> M;

	// 2차원 배열 map의 원소를 0으로 초기화해줌 
	memset(map, 0, sizeof(map));

	// 상어의 수 M에 대하여, 
	// 각각의 정보를 저장해줌
	// 여기에는 위치(x,y), 속력(speed), 방향(direction), 크기(size)에 관한 정보가 포함됨  
	for (int i = 1; i <= M; i++) {
		Shark s;
		cin >> s.x >> s.y >> s.speed >> s.direction >> s.size;

		// map의 해당 위치에 1을 표시함
		// 1을 표시하는 이유는,
		// 맵의 해당 위치에 상어의 존재 여부를 1,0으로 나타내기 위함임
		map[s.x][s.y] = 1;
		
		// 상어의 생존 여부를 true로 표시함
		s.alive = true;
		
		// 상어를 벡터 v에 넣어줌 
		v.push_back(s);
	}

	// 각 열에 대하여
	// catch_shark(), move_shark(), eat_shark()를 실행해줌
	for (int i = 1; i <= C; i++) {
		catch_shark(i);
		move_shark();
		eat_shark();
	}

	// 전체 잡은 상어의 무게를 출력함 
	cout << total;


}
