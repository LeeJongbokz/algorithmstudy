#include <string>
#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
   
	vector<int>v;
	v = priorities;
	sort(v.begin(), v.end());

	queue<pair<int, int>> q;

	for (int i = 0; i < priorities.size(); i++) {
		q.push(make_pair(priorities[i], i));
	}

	while (1) {

		int mostImportant = v.back();

		int num = q.front().first;
		int pos = q.front().second;
		q.pop();

		if (mostImportant == num) {
			answer += 1;
			v.pop_back();

			if (location == pos) {
				break;
			}

		}
		else {
			q.push(make_pair(num, pos));
		}

	}   
    
    return answer;
}
