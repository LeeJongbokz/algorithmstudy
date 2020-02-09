#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 25;
const int INF = 987654321;

int N;
int dataNum[MAX][MAX];
bool check[MAX];

vector<int> start;
vector<int> link;
int minGap = INF;


void calculate() {

	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			link.push_back(i);
		}
	}

	int startSum = 0;
	int linkSum = 0; 

	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < (N / 2); j++) {
			if (i != j) {
				startSum += dataNum[start[i]][start[j]];
				linkSum += dataNum[link[i]][link[j]];
			}
		}
	}

	int gap = abs(startSum - linkSum);

	minGap = min(minGap, gap);

	link.clear();

}




void recursive(int index, int lastNum) {

	if (index == (N / 2)) {
		calculate();
		return;
	}


	for (int i = lastNum; i <= N; i++) {
		if (check[i] == false) {
			check[i] = true;
			start.push_back(i);
			recursive(index + 1, i+1);
			start.pop_back();
			check[i] = false; 
		}
	}

}


int main() {

	memset(check, false, sizeof(check));

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dataNum[i][j];
		}
	}

	recursive(0, 1);

	cout << minGap;

}
