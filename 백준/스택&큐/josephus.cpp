#include <iostream>
#include <queue>

using namespace std;


int main() {

	int N, K;
	cin >> N >> K;

	queue<int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	cout << '<';

	while (!q.empty()) {

		for (int i = 1; i < K; i++) {
			int num = q.front();
			q.pop();
			q.push(num); 
		}

		int front = q.front();
		q.pop();
		if (!q.empty()) {
			cout << front << ", ";
		}
		else {
			cout << front;
		}
	}

	cout << '>';




}
