#include <iostream>
#include <deque>

using namespace std;

int calRight(deque<int> dq, int num) {

	int rcnt = 0; 

	while (1) {

		if (dq.front() == num) {
			break;
		}
		else {
			int rfront = dq.front();
			dq.pop_front();
			dq.push_back(rfront);
			rcnt += 1;
		}
	}

	return rcnt; 

}

int RealcalRight(deque<int> &dq, int num) {

	int rcnt = 0;

	while (1) {

		if (dq.front() == num) {
			dq.pop_front();
			break;
		}
		else {
			int rfront = dq.front();
			dq.pop_front();
			dq.push_back(rfront);
			rcnt += 1;
		}
	}

	return rcnt;

}

int calLeft(deque<int> dq, int num) {

	int lcnt = 0;

	while (1) {

		if (dq.front() == num) {
			break;
		}
		else {
			int lback = dq.back();
			dq.pop_back();
			dq.push_front(lback);
			lcnt += 1;
		}
	}

	return lcnt;

}

int RealcalLeft(deque<int> &dq, int num) {

	int lcnt = 0;

	while (1) {

		if (dq.front() == num) {
			dq.pop_front();
			break;
		}
		else {
			int lback = dq.back();
			dq.pop_back();
			dq.push_front(lback);
			lcnt += 1;
		}
	}

	return lcnt;

}






int main() {

	int N, M;
	cin >> N >> M;
	deque<int> dq;

	int cnt = 0; 

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}


	for (int i = 1; i <= M; i++) {
		int num;
		cin >> num;

		int rnum, lnum;

		if (dq.front() == num) {
			dq.pop_front();
			continue;
		}
		else {
			rnum = calRight(dq, num);
			lnum = calLeft(dq, num);
		}

		if (rnum > lnum) {
			cnt += RealcalLeft(dq, num);
		}
		else if (rnum < lnum) {
			cnt += RealcalRight(dq, num);
		}
		else {
			cnt += RealcalLeft(dq, num);
		}

	}

	cout << cnt; 







}
