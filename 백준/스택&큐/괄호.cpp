#include <iostream>
#include <stack>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int i=1; i<=T; i++){
        
        string str;
        cin >> str;
        
        int len = str.length();
        
        stack<char> stk;
        int isError = 0; 
        
        for(int j=0; j<len; j++){
            
            if(str[j] == '('){
                stk.push('(');
            }else if(str[j] == ')'){
                if(stk.empty()){
                    isError += 1;
                    break;
                }else{
                    stk.pop();
                }
            }
        }
        
        if(isError == 1){
            cout << "NO" << '\n';
            continue;
        }
        
        if(stk.empty()){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
        
     
        
    }
    
    
    
    
    
    
    
}
