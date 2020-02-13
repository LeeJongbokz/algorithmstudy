#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int len = arr1.size();
    int len1 = arr1[0].size();
    
    for(int i=0; i<len; i++){
        vector<int> temp;
        
        for(int j=0; j<len1; j++){
            temp.push_back(arr1[i][j]+arr2[i][j]);
        }
        
        answer.push_back(temp);

    }
    
    return answer;
}
