#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) {

    vector<string> answer;

    vector<vector<string>> database;
    vector<vector<string>> result;
    int resultlen = 0;
    vector<string> usedIDList;

    for (int i = 0; i < record.size(); i++) {
        string temp;

        vector<string> tempString;

        int t = 0;
        for (int j = 0; j < record[i].size(); j++) {
            if (record[i][j] != ' ') {
                temp += record[i][j];
            }
            else {
                tempString.push_back(temp);
                temp.clear();
                t += 1;
            }

            if (j == record[i].size() - 1) {
                tempString.push_back(temp);
                temp.clear();
                break;
            }

        }
        database.push_back(tempString);

    }


    for (int i = 0; i < record.size(); i++) {
        if (database[i][0] == "Enter") {

            resultlen += 1;

            bool isNew = true;

            for (int k = 0; k < usedIDList.size(); k++) {
                if (usedIDList[k] == database[i][1]) {
                    isNew = false;
                    break;
                }
            }

            if (isNew == false) {
                for (int k = 0; k < i; k++) {
                    if (result[k][2] == database[i][1]) {
                        result[k][0] = database[i][2];
                    }
                }
            }

            vector<string> tempString;
            tempString.push_back(database[i][2]);
            tempString.push_back("님이 들어왔습니다.");
            tempString.push_back(database[i][1]);

            result.push_back(tempString);

            usedIDList.push_back(database[i][1]);


        }
        else if (database[i][0] == "Leave") {

            resultlen += 1;

            vector<string> tempString;

            for (int k = 0; k < i; k++) {
                if (database[k][1] == database[i][1]) {
                    tempString.push_back(database[k][2]);
                    break;
                }
            }

            tempString.push_back("님이 나갔습니다");
            tempString.push_back(database[i][1]);
            result.push_back(tempString);

        }
        else if (database[i][0] == "Change") {

            for (int k = 0; k < i; k++) {
                if (result[k][2] == database[i][1]) {
                    result[k][0] = database[i][2];
                }
            }
        }
    }

    for (int i = 0; i < resultlen; i++){
       string tempResult;
        tempResult = result[i][0] + result[i][1];
        tempResult += '\"';
        if (i != resultlen - 1) {
            tempResult += ',';
            tempResult += ' ';
        }

        tempResult.insert(0, "\"");

        if (i == 0) {
            tempResult.insert(0, "[");
        }

        if (i == resultlen - 1) {
            tempResult.push_back(']');
        }

        answer.push_back(tempResult);
        
    }

    return answer;
}
