#include <iostream>
#include <cstring> 

using namespace std;

int N, M;
bool check[10];

void recursive(int index) {

	if (index == M) {
		for (int i = 1; i <= N; i++) {
			if (check[i] == true) {
				cout << i << " ";
			}
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			check[i] = true;
			recursive(index + 1);
			check[i] = false;
		}
	}

}


int main() {

	memset(check, false, sizeof(check));

	cin >> N >> M;

	recursive(0);


}
