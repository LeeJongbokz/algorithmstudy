#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
int linked[SWITCHES][CLOCKS + 1] = { 0 };

int C;
vector<int> clocks;

bool areAligned(const vector<int>& clocks) {
	for (int i = 0; i < CLOCKS; i++) {
		if (clocks[i] != 12) {
			return false;
		}
	}

	return true;

};


void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; clock++) {
		if (linked[swtch][clock] == 1) {
			clocks[clock] += 3;
			if (clocks[clock] == 15) {
				clocks[clock] = 3;
			}
		}
	}
}


int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) return areAligned(clocks) ? 0 : INF;

	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}

	return ret;

}

int main() {

	cin >> C;

	for (int i = 1; i <= C; i++) {

		clocks.clear();

		for (int j = 0; j < SWITCHES; j++) {

			string isConnected;
			cin >> isConnected;

			for (int k = 0; k < CLOCKS; k++) {
				int num = isConnected[k] - '0';
				
				linked[j][k] = num;
			}
		}

		for (int j = 0; j < CLOCKS; j++) {
			int num;
			cin >> num;

			clocks.push_back(num);

		}

		int result = solve(clocks, 0);

		cout << result << '\n';


	}



}
