#include <iostream>
#include <vector>

using namespace std;

bool isFriend[100][100];
bool isUsed[100];

int n, m;
int cnt = 0; 

void isParing() {

	bool isDone = true;
	int first;

	for (int i = 0; i < n; i++) {
		if (isUsed[i] == false) {
			isDone = false;
			first = i;
			break;
		}
	}

	if (isDone == true) {
		cnt += 1;
		return; 
	}


	for (int i = 0; i < n; i++) {
		if (first< i && isFriend[first][i] && isUsed[first] == false && isUsed[i] == false) {
			isUsed[first] = true;
			isUsed[i] = true;
			isParing();
			isUsed[first] = false;
			isUsed[i] = false; 
		}
	}





}

int main() {

	memset(isFriend, false, sizeof(isFriend));
	memset(isUsed, false, sizeof(isUsed));

	int C;
	cin >> C;

	for (int i = 1; i <= C; i++) {
		cin >> n >> m;

		for (int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			isFriend[a][b] = true;
			isFriend[b][a] = true;
		}

		isParing();
	}

	
	cout << cnt;

}
