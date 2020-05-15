#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int len;
int tupleLen;

vector<vector<string>> relations;

vector<vector<string>> result;
vector<vector<string>> result1;
vector<vector<string>> result2;
vector<string> finalResult;

bool check[10000];
bool check1[100];
bool check2[100];

void getColumn(vector<int> &picked) {

	result.clear(); 

	for (int i = 0; i < len; i++) {

		vector<string> temp;

		for (int j = 0; j < picked.size(); j++) {
			int pos = picked[j];
			temp.push_back(relations[i][pos - 1]);
		}

		result.push_back(temp);
	}


}


bool isUnique() {

	result1.clear(); 

	result1 = result;
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	if (result.size() == result1.size()) {
		return true;
	}
	else {
		return false;
	}

}

void isMinimal() {


	for (int i = 0; i < finalResult.size(); i++) {

		string temp1 = finalResult[i];

		for (int j = i + 1; j < finalResult.size(); j++) {

			if (check[j] == false) {
				continue;
			}

			memset(check1, false, sizeof(check1));
			memset(check2, false, sizeof(check2));

			string temp2 = finalResult[j];
			
			for (int k = 0; k < temp1.size(); k++) {
				int num = temp1[k] - '0';
				check1[num] = true;
			}

			for (int k = 0; k < temp2.size(); k++) {
				int num = temp2[k] - '0';
				check2[num] = true;
			}

			bool isCheck = true;

			for (int k = 0; k < temp1.size(); k++) {
				int num = temp1[k] - '0';
				if (check1[num] == true && check2[num] == true) {
					continue;
				}
				else {
					isCheck = false;
                    break;
				}
			}

			if (isCheck == true) {
				check[j] = false;
			}
			
		}

	}



}


void recursive(int cnt, int total, vector<int>& picked) {

	if (cnt == total) {
		getColumn(picked);
		bool uniqueResult = isUnique();

		if (uniqueResult == true) {
			string str;
			for (int i = 0; i < picked.size(); i++) {
				str += to_string(picked[i]);
			}
			finalResult.push_back(str);
		}

		return; 

	}

	int lastPick = picked.empty() ? 1 : picked.back() + 1;

	for (int i = lastPick; i <= tupleLen; i++) {
		picked.push_back(i);
		recursive(cnt + 1, total, picked);
		picked.pop_back();
	}

}


int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    len = relation.size(); 
    tupleLen = relation[0].size();
    
    relations = relation;

	memset(check, true, sizeof(check));

	len = relation.size();
	tupleLen = relation[0].size();

	for (int i = 1; i <= tupleLen; i++) {
		vector<int> picked;
		recursive(0, i, picked);
	}

	isMinimal();
    
    for (int i = 0; i < finalResult.size(); i++) {
		if (check[i] == true) {
			answer += 1;
		}
	}
    
    return answer;
}
