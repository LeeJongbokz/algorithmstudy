#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;


bool cmp(const pair<int, int> &a, const pair<int, int> &b) {

	if (a.first < b.first) {
		return true;
	}
	else if (a.first == b.first) {
		if (a.second < b.second) {
			return true;
		}
		else {
			return false;
		}
	}

	return false; 

}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}

}
