#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 50;
int N, M, empty_place, ans = 1000000000;
int MAP[MAX][MAX];
int CMAP[MAX][MAX];		// depth를 담을 배열

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector<pair<int, int>> virus, active;	// 전체 바이러스와 활성 바이러스를 담을 벡터
bool check[10];	// 활성 바이러스 선택한거 체크

/// 뽑은 바이러스 위치만 0으로 변경
void copy_map() {
	memset(CMAP, -1, sizeof(CMAP));

	for (int i = 0; i < active.size(); i++) {
		CMAP[active[i].first][active[i].second] = 0;
	}
}

bool is_Range(int nx, int ny) {
	if (nx >= 0 && nx < N && ny >= 0 && ny < N)
		return true;
	else return false;
}

/// 활성바이러스 확산 + 다 퍼지는데 걸리는 시간 리턴
void bfs() {
	int virus_place = 0;
	int max_time = 0;

	queue < pair <int, int> > q;
	for (int i = 0; i < active.size(); i++) {
		q.push(active[i]);				// 활성 바이러스 M개 q에 push
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (is_Range(nx, ny)) {
				if (MAP[nx][ny] != 1 && CMAP[nx][ny] == -1) {	// 비활성 바이러스이거나, 0이면서 방문안한 곳으로 진입
					CMAP[nx][ny] = CMAP[x][y] + 1;
					q.push(make_pair(nx, ny));

					if (MAP[nx][ny] == 0) {
						virus_place++;		// 빈공간을 하나씩 다시 새본다
						max_time = CMAP[nx][ny];	// 마지막에 들어가는 값이 가장 큰 시간임
					}
				}
			}
		}
	}
	if (virus_place == empty_place)
		ans = min(ans, max_time);

}

void dfs(int cnt, int index) {
	if (cnt == M) {
		copy_map();
		bfs();
		return;
	}
	for (int i = index; i < virus.size(); i++) {
		if (check[i] == true) continue;
		check[i] = true;
		active.push_back(virus[i]);
		dfs(cnt + 1, i);
		check[i] = false;
		active.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 0) empty_place++;	// 빈공간의 개수를 카운트
			else if (MAP[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}
	}
	dfs(0, 0);
	if (ans == 1000000000)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
	return 0;
}
