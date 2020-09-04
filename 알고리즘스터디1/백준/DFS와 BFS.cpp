#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int>a[1010];
bool check[1010];

void dfs(int num) {

	check[num] = true;
	cout << num << " ";

	for (int i = 0; i < a[num].size(); i++) {
		int y = a[num][i];

		if (check[y] == false) {
			dfs(y);
		}
	}

}

void bfs(int start) {

	queue<int> q;
	q.push(start);

	
	while (!q.empty()) {
		int num = q.front();
		check[num] = true; 
		q.pop();
		cout << num << " ";

		for (int i = 0; i < a[num].size(); i++) {
			int y = a[num][i];

			if (check[y] == false) {
				check[y] = true;
				q.push(y);
			}
		}

	}



}

int main() {
	
	int N, M, V;
	cin >> N >> M >> V;

	memset(check, false, sizeof(check));

	for (int i = 1; i <= M; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(V);

	cout << '\n';

	memset(check, false, sizeof(check));

	bfs(V);
	



}
