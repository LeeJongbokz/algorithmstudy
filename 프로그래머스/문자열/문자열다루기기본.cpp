#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    
    bool answer = true;
    
    int len = s.length();
    
    if(len == 4 || len == 6){
        for(int i=0; i<len; i++){
            if(48<=s[i] && s[i]<=57){
                continue;
            }else{
                answer = false;
                break;
            }
        }
    }else{
        answer = false;
    }
    
    return answer;
}
