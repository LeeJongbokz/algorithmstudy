#include <iostream>
#include <deque>
#include <string>

using namespace std;

int N;


int main() {

	// 변수 N에 전체 명령의 수를 입력함 
	cin >> N;

	// 덱을 선언함
	// 덱을 선언하기 위해서는 #include <deque>을 하고,
	// deque<int> dq; 이런 식으로 선언을 해줘야 함
	// deque은 double-ended queue의 줄임말임 
	deque<int> dq;

	// 전체 명령의 수만큼, 
	// string에 값을 입력함 
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str; 

		// str이 push_front라면
		// dq에 push_front 명령을 입력함 
		if (str == "push_front") {
			int num;
			cin >> num;
			dq.push_front(num);
		}
		// str이 push_back이라면
		// dq에 push_back 명령을 입력함 
		else if (str == "push_back") {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		// str이 pop_front라면
		// dq가 empty일 때는, 1을 출력하고
		// dq가 empty가 아닐 때는 pop_front 명령을 입력함 
		// 단, 수를 출력해야 하므로, 그 수를 미리 변수 num에 넣어야 함  
		else if (str == "pop_front") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				int num = dq.front();
				dq.pop_front();
				cout << num << '\n';
			}
		}
		// str이 pop_back이라면
		// dq가 empty일 때는, -1을 출력하고
		// dq가 empty가 아닐 때는 pop_back 명령을 입력함
		// 단, 수를 출력해야 하므로, 그 수를 미리 변수 num에 넣어야 함 
		else if (str == "pop_back") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				int num = dq.back();
				dq.pop_back();
				cout << num << '\n';
			}

		}
		// str이 size라면
		// dq의 size를 출력함
		else if (str == "size") {
			cout << dq.size() << '\n';
		}
		// str이 empty라면
		// dq가 empty인 경우는 1을
		// dq가 empty가 아닌 경우는 0을 출력함 
		else if (str == "empty") {
			if (dq.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		// str이 front라면
		// dq가 empty인 경우는 -1을
		// 아닌 경우는 dq.front()를 출력함 
		else if (str == "front") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.front() << '\n';
			}
		}
		
		// str이 back이라면
		// dq가 empty인 경우는 -1을
		// 아닌 경우는 dq.back()을 출력함 
		else if (str == "back") {
			if (dq.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << dq.back() << '\n';
			}
		}

	}

}
