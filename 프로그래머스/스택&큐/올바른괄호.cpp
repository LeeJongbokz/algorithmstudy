#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int len = s.length();
    stack<char> stk;
    int isError = 0;
    
    for(int i=0; i<len; i++){
        
        if(s[i] == '('){
            stk.push('(');
        }else if(s[i] == ')'){
            if(stk.empty()){
                isError += 1;
                break;
            }else{
                stk.pop();
            }
        }
    }
    
    if(isError == 1){
        answer = false;
    }else{
        if(stk.empty()){
            answer = true;
        }else{
            answer = false; 
        }
    }
    

    return answer;
}
