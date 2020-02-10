#include <string>
#include <vector>
#include <stack> 

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    
    
    stack<char> stk;
    
    int len = arrangement.length();
    
    int cnt = 0; 
    
    for(int i=0; i<len; i++){
        
        if(arrangement[i] == '('){
            stk.push('(');
        }else{
            stk.pop();
            
            if(arrangement[i-1] == '('){
                cnt += stk.size();
            }else if(arrangement[i-1] == ')'){
                cnt += 1;
            }

        }
    }
    
    answer = cnt;
    
    return answer; 
}
