#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath> 

using namespace std;

int getNum(vector<char> v) {

	int result = 0;
	int t = 0;
	vector<char> temp;
	temp = v;

	while (!temp.empty()) {

		int num;

		if (48 <= temp.back() && temp.back() <= 57) {
			num = temp.back() - 48;
		}
		else if (65 <= temp.back() && temp.back() <= 70) {
			num = temp.back() - 55;
		}

		result += num * pow(16, t);
		t += 1;
		temp.pop_back();

	}

	return result; 
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		cin >> N >> K;

		vector<int> result;

		vector<char> v1;
		vector<char> v2;
		vector<char> v3;
		vector<char> v4;

		for (int j = 0; j < N / 4; j++) {
			char num;
			cin >> num;
			v1.push_back(num);
		}

		for (int j = 0; j < N / 4; j++) {
			char num;
			cin >> num;
			v2.push_back(num);
		}

		for (int j = 0; j < N / 4; j++) {
			char num;
			cin >> num;
			v3.push_back(num);
		}

		for (int j = 0; j < N / 4; j++) {
			char num;
			cin >> num;
			v4.push_back(num);
		}

		result.push_back(getNum(v1));
		result.push_back(getNum(v2));
		result.push_back(getNum(v3));
		result.push_back(getNum(v4));

		int rotate = (N / 4) - 1;

		while (rotate--) {

			char v1Num = v1.back();
			v2.insert(v2.begin(), v1Num);
			v1.pop_back();

			char v2Num = v2.back();
			v3.insert(v3.begin(), v2Num);
			v2.pop_back();

			char v3Num = v3.back();
			v4.insert(v4.begin(), v3Num);
			v3.pop_back();

			char v4Num = v4.back();
			v1.insert(v1.begin(), v4Num);
			v4.pop_back();

			result.push_back(getNum(v1));
			result.push_back(getNum(v2));
			result.push_back(getNum(v3));
			result.push_back(getNum(v4));


		}


		sort(result.begin(), result.end(), greater<int>());
		result.erase(unique(result.begin(), result.end()), result.end());

		cout << '#' << test_case << " " << result[K - 1] << '\n';





	}


	return 0;
}
