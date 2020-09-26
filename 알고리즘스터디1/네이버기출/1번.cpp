#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <stack> 

using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }

    return internal;
}

int main() {

    vector<string> record;
    record.push_back("RECEIVE abcd@naver.com");
    record.push_back("RECEIVE zzkn@naver.com");
    record.push_back("DELETE");
    record.push_back("RECEIVE qwerty@naver.com");
    record.push_back("SAVE");
    record.push_back("SAVE");
    record.push_back("DELETE");
    record.push_back("RECEIVE QwerTY@naver.com");
    record.push_back("SAVE");

    stack<string> stk;
    vector<string> result; 


    for (int i = 0; i < record.size(); i++) {

        vector<string> temp;

        vector<string> v = split(record[i], ' ');

        if (v[0] == "RECEIVE") {
            stk.push(v[1]);
        }
        else if (v[0] == "DELETE") {
            if (!stk.empty()) {
                stk.pop();
            }
        }
        else if (v[0] == "SAVE") {
            
            while (!stk.empty()) {
                string top = stk.top();
                temp.push_back(top);
                stk.pop();
            }

            reverse(temp.begin(), temp.end());

            for (int i = 0; i < temp.size(); i++) {
                result.push_back(temp[i]);
            }
        }

    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

}
