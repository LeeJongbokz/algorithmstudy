#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 15;

int C;
bool isFriends[MAX][MAX];
bool isPair[MAX];
int cnt = 0; 

int isPairing(int n) {

	int start = -1;

	for (int i = 0; i < n; i++) {
		if (isPair[i] == false) {
			start = i;
			break;
		}
	}

	if (start == -1) {
		cnt += 1;
		return;
	}
  
  int ret = 0; 

	for (int i = start + 1; i < n; i++) {
		if (isFriends[start][i] && isPair[start] == false && isPair[i] == false) {
			isPair[start] = isPair[i] = true;
			ret += isPairing(n);
			isPair[start] = isPair[i] = false;
		}
	}

  return ret;
  
}



int main() {

	cin >> C;

	for (int i = 1; i <= C; i++) {

		memset(isFriends, false, sizeof(isFriends));
		memset(isPair, false, sizeof(isPair));

		int n, m;

		cin >> n >> m;

		for (int j = 1; j <= m; j++) {
			int a, b;
			cin >> a >> b;

			isFriends[a][b] = true;
			isFriends[b][a] = true;
		}

		isPairing(n);

		cout << cnt << '\n';
	}

}
