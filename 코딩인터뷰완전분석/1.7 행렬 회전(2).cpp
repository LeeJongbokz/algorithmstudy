#include <iostream>

using namespace std;

int arr[30][30];
int N;

void transpose(int arr[][30], int N) {

	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}


}


void reverseColumns(int arr[][30], int N) {

	for (int i = 1; i <= N; i++) {
		for (int j = 1, k=N; j < k; j++, k--) {
			int temp = arr[i][j];
			arr[i][j] = arr[i][k];
			arr[i][k] = temp;
		}
	}

}


void rotate(int arr[][30], int N) {
	transpose(arr, N);
	reverseColumns(arr, N);
}



int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	rotate(arr, N);

	cout << '\n';


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}





}





