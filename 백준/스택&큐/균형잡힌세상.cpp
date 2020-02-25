#include <iostream>
#include <stack>
#include <string> 

using namespace std;

int main(){
    
    while(1){
        
        string str;
        getline(cin, str);
        
        int len = str.length();
        
        if(str == "."){
            break;
        }
        
        stack<char> stk;
        
        int isError = 0;
        
        for(int i=0; i<len; i++){
            
            if(str[i] == '['){
                stk.push('[');
            }else if(str[i] == '('){
                stk.push('(');
            }else if(str[i] == ']'){
                
                if(stk.empty()){
                    isError += 1;
                    break;
                }else if(stk.top() == '('){
                    isError += 1;
                    break;
                }else if(stk.top() == '['){
                    stk.pop();
                }
                
            }else if(str[i] == ')'){
                
                if(stk.empty()){
                    isError += 1;
                    break;
                }else if(stk.top() == '['){
                    isError += 1;
                    break;
                }else if(stk.top() == '('){
                    stk.pop();
                }
                
            }else{
                continue;
            }
           
        }
        
        if(isError == 1){
            cout << "no" << '\n';
            continue;
        }
        
        if(stk.empty()){
            cout << "yes" << '\n';
        }else{
            cout << "no" << '\n';
        }
        
        
        
    }
    
   
    
    
}
