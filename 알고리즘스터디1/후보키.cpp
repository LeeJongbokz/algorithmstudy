#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <set> 
#include <algorithm> 

using namespace std;

bool check[10];
bool check2[200];
vector<string> uniqueList;

bool cmp(string& a, string& b) {
    if (a.size() < b.size()) {
        return true;
    }
    else {
        return false;
    }
}

bool isUnique(vector<int>v, vector<vector<string>> relation) {

    vector<vector<string>> tempResult;
    set<vector<string>> s;

    for (int i = 0; i < relation.size(); i++) {
        vector<string> temp;

        for (int j = 0; j < v.size(); j++) {
            int pos = v[j];
            temp.push_back(relation[i][pos]);
        }

        tempResult.push_back(temp);
        s.insert(temp);
    }

    int tempLen = tempResult.size();
    int sLen = s.size();

    if (tempLen == sLen) {
        return true;
    }
    else {
        return false;
    }
}

void recursive(int cnt, int colSize, vector<int>& v, vector<vector<string>> relation) {

    if (1 <= cnt && cnt <= colSize) {

    
        bool result = isUnique(v, relation);
       
        string temp;

        if (result) {
            for (int i = 0; i < v.size(); i++) {
                temp += to_string(v[i]);
            }

            uniqueList.push_back(temp);
        }

        if (cnt == colSize) {
            return;
        }
    }

    int lastPick = v.empty() ? 0 : v.back() + 1;

    for (int i = lastPick; i < colSize; i++) {
        if (check[i] == false) {
            check[i] = true;
            v.push_back(i);
            recursive(cnt + 1, colSize, v, relation);
            v.pop_back();
            check[i] = false;
        }
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;

    memset(check, false, sizeof(check));
    memset(check2, true, sizeof(check2));

    int colSize = relation[0].size();
    vector<int>v;

    recursive(0, colSize, v, relation);

    sort(uniqueList.begin(), uniqueList.end(), cmp);

    for (int i = 0; i < uniqueList.size(); i++) {
        cout << uniqueList[i] << " ";
    }

    int cnt = 1; 

    "14" "13" "123"

    for (int i = 0; i < uniqueList.size(); i++) {

        for (int j = 0; j < uniqueList.size(); j++) {
            if (i != j && uniqueList[i].size() < uniqueList[j].size()) {
                string temp = uniqueList[i] + uniqueList[j];
                bool isUnable = false;

                sort(temp.begin(), temp.end());

                for (int k = 0; k < temp.size()-1; k++) {
                    if (temp[k] == temp[k + 1]) {
                        isUnable = true;
                        break;
                    }
                }

                if (isUnable == true) {
                    check2[j] = false; 
                }

            }
        }
    }

    for (int i = 0; i < uniqueList.size(); i++) {
        if (check2[j] == true) {
            answer += 1; 
        }
    }



    return answer;
}


int main() {

    vector<vector<string>>relation;
    vector<string>temp;
    temp.push_back("100");
    temp.push_back("ryan");
    temp.push_back("music");
    relation.push_back(temp);
    temp.clear();
    temp.push_back("200");
    temp.push_back("apeach");
    temp.push_back("math");
    relation.push_back(temp);
    temp.clear();
    temp.push_back("300");
    temp.push_back("tube");
    temp.push_back("computer");
    relation.push_back(temp);
    temp.clear();
    temp.push_back("400");
    temp.push_back("con");
    temp.push_back("computer");
    relation.push_back(temp);
    temp.clear();

    int result = solution(relation);

    cout << '\n';
    cout << result; 
}
