#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> clockWise[20];
vector<pair<int, int>> unClockWise[20];
bool visited[20];
bool used[20];

bool cmp(pair<int, int>& a, pair<int, int>& b) {

	if (a.second < b.second) {
		return true;
	}
	else if (a.second == b.second) {
		if (a.first < b.first) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false; 
	}
}


int main() {

	int n;
	n = 12;

	for (int i = 0; i < 20; i++) {
		clockWise[i].push_back(make_pair(0, 0));
	}

	for (int i = 0; i < 20; i++) {
		unClockWise[i].push_back(make_pair(0, 0));
	}

	vector<int> weak;
	weak.push_back(1);
	weak.push_back(5);
	weak.push_back(6);
	weak.push_back(10);

	vector<int>dist;
	dist.push_back(1);
	dist.push_back(2);
	dist.push_back(3);
	dist.push_back(4);


	for (int i = 0; i < weak.size(); i++) {

		int num = weak[i];
		
		//clockwise
		for (int j = 1; j <= 100; j++) {
			int cnt = 1; 
			int start = num;
			int end = num + j;

			for (int k = 0; k < weak.size(); k++) {
				if (i == k) {
					continue;
				}
				else {

					if (end < n) {
						if (start <= weak[k] && weak[k] <= end) {
							cnt += 1;
						}
					}
					else if (end >= n) {
						if ((start <= weak[k] && weak[k] <= n) || (0 <= weak[k] && weak[k] <= end - n)) {
							cnt += 1;
						}
					}
				}
			}

			clockWise[i].push_back(make_pair(j, cnt));

		}


		//unClockWise;
		for (int j = 1; j <= 100; j++) {
			int cnt = 1;
			int start = num;
			int end = num - j;

			for (int k = 0; k < weak.size(); k++) {
				if (i == k) {
					continue;
				}
				else {
					if (end >= 0) {
						if (end <= weak[k] && weak[k] <= start) {
							cnt += 1;
						}
					}
					else {
						if ( (0 <= weak[k] && weak[k] <= start) || (n + end <= weak[k]) && (weak[k] <= n)) {
							cnt += 1;
						}
					}
				}
			}

			unClockWise[i].push_back(make_pair(j, cnt));
		}
	}


	sort(dist.begin(), dist.end());

	int result = 0; 
	memset(visited, false, sizeof(visited));
	memset(used, false, sizeof(used));
	
	while (1) {

		bool isDone = true;
		bool usedAll = true;

		for (int i = 0; i < weak.size(); i++) {
			if (visited[i] == false) {
				isDone = false;
				break;
			}
		}

		for (int i = 0; i < dist.size(); i++) {
			if (used[i] == false) {
				usedAll = false;
				break;
			}
		}

		if (isDone == true) {
			break;
		}

		if (usedAll == true) {
			break; 
		}

		vector<pair<int, int>>v;
		vector<pair<int, int>>maxCnts;

		for (int i = 0; i < dist.size(); i++) {

			if (used[i] == true) {
				continue; 
			}

			int distance = dist[i];
			int maxCnt = 0;
			int direction = 1;
			int maxPos = 0;

			for (int j = 0; j < weak.size(); j++) {
				if (maxCnt < clockWise[j][distance].second) {
					maxCnt = clockWise[j][distance].second;
					direction = 1;
					maxPos = j;
				}
				if (maxCnt < unClockWise[j][distance].second) {
					maxCnt = unClockWise[j][distance].second;
					direction = -1;
					maxPos = j;
				}
			}

			maxCnts.push_back(make_pair(i, maxCnt));
			v.push_back(make_pair(maxPos, direction));

		}

		sort(maxCnts.begin(), maxCnts.end(), cmp);
		int choosePos = maxCnts[0].first;
		used[choosePos] = true;
		result += 1;

		int pos = v[choosePos].first;
		int num = maxCnts[0].second;

		if (v[choosePos].second == 1) {
			while (num--) {
				if (visited[pos] == false) {
					visited[pos] = true;
				}
				pos += 1;
				pos %= weak.size();
			}
		}
		else {

			while (num--) {
				if (visited[pos] == false) {
					visited[pos] = true;
				}
				pos -= 1;
				pos += weak.size();
			}
		}
	}

	bool isCheck = true;

	for (int i = 0; i < weak.size(); i++) {
		if (visited[i] == false) {
			isCheck = false;
			break;
		}
	}

	if (isCheck) {
		cout << result;
	}
	else {
		cout << -1;
	}


}
