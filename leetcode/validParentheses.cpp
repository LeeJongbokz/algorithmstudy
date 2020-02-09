#include <stack> 

class Solution {
public:
    bool isValid(string s) {
        
        int len = s.size();
        stack<char> stk;
        bool isError = false;
        
        for(int i=0; i<len; i++){
            if(s[i] == '('){
                stk.push('(');
            }else if(s[i] == '['){
                stk.push('[');
            }else if(s[i] == '{'){
                stk.push('{');
            }else if(s[i] == ')'){
                if(!stk.empty()){
                    char a = stk.top();
                    if(a == '('){
                        stk.pop();
                    }else{
                        isError = true;
                        break;
                    }
                }else{
                    isError = true;
                    break;
                }
            }else if(s[i] == ']'){
               if(!stk.empty()){
                    char a = stk.top();
                    if(a == '['){
                        stk.pop();
                    }else{
                        isError = true;
                        break;
                    }
                }else{
                    isError = true;
                    break;
                }
            }else if(s[i] == '}'){
               if(!stk.empty()){
                    char a = stk.top();
                    if(a == '{'){
                        stk.pop();
                    }else{
                        isError = true;
                        break;
                    }
                }else{
                    isError = true;
                    break;
                }
            }
        
        }
        
        if(stk.size() >= 1){
            isError = true; 
        }
        
        if(isError == true){
            return false;
        }else{
            return true;
        }
    }
        
        
};
