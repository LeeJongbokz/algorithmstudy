#include <iostream>
#include <stack>

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    int len =str.length();
    
    stack<char> stk;
    int cnt = 0;
    
    for(int i=0; i<len; i++){
        if(str[i] == '('){
            stk.push('(');
        }else if(str[i] == ')'){
            if(str[i-1] == '('){
                stk.pop();
                cnt += stk.size();
            }else if(str[i-1] == ')'){
                stk.pop();
                cnt += 1;
            }
        }
    }
    
    
    cout << cnt;
    
    
    
    
    
    
    
}
