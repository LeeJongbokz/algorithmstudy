#include <iostream>
#include <vector>

using namespace std;

int longest = 0; 
bool check[10];

void LIS(vector<int>&idx, vector<int>& input) {

	if (idx.size() > longest) {
		longest = idx.size();
		for (int i = 0; i < idx.size(); i++) {
			cout << input[idx[i]] << " ";
		}
		cout << '\n';
	}

	int lastPick = idx.empty() ? 0 : idx.back() + 1;

	for (int i = lastPick; i < input.size(); i++) {
		if (check[i] == false) {
			if (idx.empty()) {
				check[i] = true;
				idx.push_back(i);
				LIS(idx, input);
				idx.pop_back();
				check[i] = false;
			}
			else {
				if (idx.back() < input[i]) {
					check[i] = true;
					idx.push_back(i);
					LIS(idx, input);
					idx.pop_back();
					check[i] = false; 
				}
			}
		}
	}



}

int main() {

	memset(check, false, sizeof(check));

	vector<int>input;
	input.push_back(1);
	input.push_back(5);
	input.push_back(6);
	input.push_back(2);
	input.push_back(7);
;
	vector<int>idx;

	LIS(idx, input);




}
