#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct score {
	string str;
	int x;
	int y;
	int z;
};


bool cmp(score a, score b) {

	if (a.x > b.x) {
		return true;
	}
	else if (a.x == b.x) {
		if (a.y < b.y) {
			return true;
		}
		else if (a.y == b.y) {
			if (a.z > b.z) {
				return true;
			}
			else if (a.z == b.z) {

				int len1 = a.str.length();
				int len2 = b.str.length();

				int len = min(len1, len2);

				for (int i = 0; i < len; i++) {
					if (a.str[i] < b.str[i]) {
						return true;
					}
					else if (a.str[i] == b.str[i]) {
						continue;
					}
					else {
						return false;
					}
				}


			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

	return false;


}



int main() {

	int N;
	cin >> N;

	vector<score> v(N);

	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		int k, m, e;
		cin >> k >> m >> e;

		v[i].str = name;
		v[i].x = k;
		v[i].y = m;
		v[i].z = e;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << v[i].str << '\n';
	}




}
