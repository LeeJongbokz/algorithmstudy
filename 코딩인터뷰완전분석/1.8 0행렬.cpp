#include <iostream>
#include <vector>

using namespace std;

int main() {

	int M, N;
	cin >> M >> N;

	int arr[30][30];
	vector<int> isRow;
	vector<int> isCol;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				isRow.push_back(i);
				isCol.push_back(j);
			}
		}
	}


	for (int i = 0; i < isRow.size(); i++) {
		int row = isRow[i];

		for (int j = 1; j <= N; j++) {
			arr[row][j] = 0;
		}
	}


	for (int i = 0; i < isCol.size(); i++) {
		int col = isCol[i];

		for (int j = 1; j <= M; j++) {
			arr[j][col] = 0;
		}
	}



	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}




	

	



}




