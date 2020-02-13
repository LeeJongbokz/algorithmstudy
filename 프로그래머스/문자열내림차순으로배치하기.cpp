#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int len = s.size();
    vector<int> v;
    
    for(int i=0; i<len; i++){
        v.push_back(s[i]);
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    for(int i=0; i<len; i++){
        answer += v[i];
    }
    
    
    return answer;
}
