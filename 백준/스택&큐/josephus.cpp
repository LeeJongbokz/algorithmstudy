#include <iostream>
#include <queue>

using namespace std;


int main() {

	// 변수 N과 K에 값을 입력 받는다
	// N은 전체 사람의 수를,
	// K는 제거해야 할 사람의 순서를 의미한다 
	int N, K;
	cin >> N >> K;

	// 새로운 큐인 q를 선언한다
	queue<int> q;

	// 큐에 1부터 N까지의 수를 입력한다
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	// 출력 형식을 맞추기 위해서
	// '<'를 출력한다 
	cout << '<';

	
	while (!q.empty()) {

		//  K번째 사람을 제거하기 위해,
		//  K-1명의 사람을 큐의 앞에서 제거해서
		//  맨 뒤로 옮겨준다 
		for (int i = 1; i < K; i++) {
			int num = q.front();
			q.pop();
			q.push(num); 
		}

		// K번째 수를 큐에서 제거한다
		// 제거한 수는 front 변수에 저장한다. 
		int front = q.front();
		q.pop();
		
		// front 변수에 저장한 수를 출력한다 
		if (!q.empty()) {
			cout << front << ", ";
		}
		else {
			cout << front;
		}
	}

	// 출력 형식을 맞추기 위해 '>'를 출력한다 
	cout << '>';




}
