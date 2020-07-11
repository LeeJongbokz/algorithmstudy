#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 100010;

pair<pair<string, int>, pair<int, int>> student[MAX];

// cmp 함수로 정렬함
bool cmp(pair<pair<string, int>, pair<int, int>> &a, pair<pair<string, int>, pair<int, int>> &b) {

	if (a.first.second > b.first.second) {
		return true;
	}
	else if (a.first.second == b.first.second) {

		if (a.second.first < b.second.first) {
			return true;
		}
		else if (a.second.first == b.second.first) {
			if (a.second.second > b.second.second) {
				return true;
			}
			else if (a.second.second == b.second.second) {
				return a.first.first < b.first.first;
			}
			else {
				return false;
			}
		}
	}

	return false;

}



int main() {

	int N;
	cin >> N;

  // 이름, 국어, 수학, 영어 점수를 각각 입력 받음
	for (int i = 0; i < N; i++) {
		cin >> student[i].first.first >> student[i].first.second >> student[i].second.first >> student[i].second.second;
	}
	
  // 정렬을 함
	sort(student, student + N, cmp);

	for (int i = 0; i < N; i++) {
		cout << student[i].first.first << '\n';
	}

}
