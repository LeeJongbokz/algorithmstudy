  
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N, M, V;

// 이것은 정점을 선언해주는 것이다.
// 그리고 각 정점에서 연결된 모든 다른 정점을 저장해주는 것이다. 

vector<int> a[1010];
bool check[1010];



void dfs(int x) {
	
	// 방문한 정점은 true로 표시해준다.
	// 왜냐하면 방문한 정점은 다시 방문할 필요가 없기 때문이다. 
	// 모든 정점을 한 번씩만 탐색하는 것이 목표이기 때문이다. 
	check[x] = true;
	cout << x << " ";

	for (int i = 0; i < a[x].size(); i++) {
		// x에 연결된 정점을 순서대로 체크한다.
		// 이 때, dfs이므로, 정점에서 연결된 것이 있다면 바로 다음 정점으로 순환호출을 통해서 진입한다. 
		int y = a[x][i];

		// 아직 방문하지 않은 정점만 방문하면 되므로, check[y] == false일때만 순환호출을 통해서 진입한다. 
		if (check[y] == false) {
			dfs(y);
		}
	}


}


void bfs(int x) {

	// BFS이므로 큐를 사용한다.
	// 첫번째 원소는 바로 q에 넣어준다. 
	queue<int> q;
	q.push(x);
	

	while (!q.empty()) {

		// 맨 앞에 있는 원소를 확인하고 꺼내준다. 
		int x = q.front();
		// 방문한 점은 반드시 방문 처리를 해줘야 한다.
		// 그렇지 않으면 무한 루프를 돌게 된다. 
		check[x] = true;
		q.pop();
		cout << x << " ";

		for (int i = 0; i < a[x].size(); i++) {
			// 특정한 정점에 연결된 정점의 값을 반환한다. 
			int y = a[x][i];

			// 마찬가지로 방문하지 않은 점에 대해서만
			// 그 점을 큐에 넣어준다. 
			// bfs이므로 한 정점에서 연결된 모든 정점을 
			// 한 번에 큐에 넣어준다. 
			if (check[y] == false) {
				check[y] = true;
				q.push(y);
			}

		}



	}
	





}



int main() {

	cin >> N >> M >> V;

	for (int i = 1; i <= M; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
     
	// 정점이 여러 개인 경우, 정점 번호가 작은 것을 먼저 방문해야 한다. 
	// 예를 들어 a[0][0] = 3, a[0][1] = 2, a[0][2] = 1과 같이 되어 있는 경우는
	// 정점 번호가 작은 것부터 방문하는 것이 불가능하므로,
	// 이런 경우에는 sort를 통해서 a[0][0]= 1, a[0][1] = 2, a[0][2] = 3
	// 과 같이 오름차순으로 정렬을 해줘야 한다. 

	for (int i = 1; i <= N; i++) {
		sort(a[i].begin(), a[i].end());
	}

	memset(check, false, sizeof(check));

	dfs(V);

	cout << '\n';

	memset(check, false, sizeof(check));

	bfs(V);


}
