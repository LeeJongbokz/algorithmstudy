#include <iostream>
#include <vector>

using namespace std;

int N;
int cnt = 0; 
vector<pair<int, int>>v;

void recursive(int start, int mid, int end, int N) {

	if (N == 1) {
		v.push_back(make_pair(start, end)); 
		cnt += 1;
		return;
	}

	recursive(start, end, mid, N - 1);
	v.push_back(make_pair(start, end));
	recursive(mid, start, end, N - 1);


}



int main() {

	cin >> N;

	recursive(1, 2, 3, N);

	cout << v.size() << '\n';

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}

}
