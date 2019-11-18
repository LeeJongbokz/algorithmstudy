#include <iostream>
#include <vector>

using namespace std;


void pick(int n, vector<int>& picked, int toPick) {

	if (toPick == 0) {
		for (auto i : picked) {
			cout << i << " ";
		}
		cout << '\n';
		return;
	}

	int smallest = 0;

	if (picked.empty()) {
		smallest = 1;
	}
	else {
		smallest = picked.back() + 1;
	}

	for (int i = smallest; i <= n; i++) {
		picked.push_back(i);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}



}



int main() {

	int n, m;
	cin >> n >> m;

	vector<int> v;

	pick(n, v, m);


}
