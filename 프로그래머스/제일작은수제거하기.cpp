#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    sort(arr.begin(), arr.end(), greater<int>());
    
    int len = arr.size();
    
    if(len == 1){
        answer.push_back(-1);
    }else{
        for(int i=0; i<len-1; i++){
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}
