#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100
#define INF 9999999

using namespace std;

int n;
double dist[MAX][MAX] = { 0 };
bool visited[MAX] = { 0 };
vector<int> path; 


double shortestPath(vector<int>& path, bool visited[MAX] , double currentLength) {

	if (path.size() == n) {
		return currentLength + dist[path[0]][path.back()];
	}

	double ret = INF;

	for (int next = 0; next < n; next++) {
		if (visited[next]) continue;

		int here; 

		if (path.empty()) {
			here = 0;
		}
		else {
			here = path.back();
		}
		path.push_back(next);
		visited[next] = true;

		double cand = shortestPath(path, visited, currentLength + dist[here][next]);

		ret = min(ret, cand);
			
		visited[next] = false;
		path.pop_back();

	}

	return ret; 

}



int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;

			dist[i][j] = num;
		}
	}

	int result = shortestPath(path, visited, 0);

	cout << result; 


}
