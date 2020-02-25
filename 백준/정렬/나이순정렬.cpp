#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 

using namespace std;


bool cmp(pair<int, pair<int,string>> a, pair<int, pair<int,string>> b) {

	if (a.second.first < b.second.first) {
		return true;
	}
	else if (a.second.first == b.second.first) {
		if (a.first < b.first) {
			return true;
		}
		else {
			return false;
		}

	}else{
		return false;
	}
}



int main() {

	int N;
	cin >> N;

	vector<pair<int, pair<int, string>>> v(N);

	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> age >> name;

		v[i].first = i+1;
		v[i].second.first = age;
		v[i].second.second = name;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << v[i].second.first << " " << v[i].second.second << '\n';
	}


}




