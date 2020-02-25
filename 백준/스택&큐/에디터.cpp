#include <iostream>
#include <stack>

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    int len = str.length();
    
    stack<char> stk1;
    stack<char> stk2;
    
    for(int i=0; i<len; i++){
        stk1.push(str[i]);
    }
    
    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++){
        char input;
        cin >> input;
        
        if(input == 'P'){
            char c;
            cin >> c;
            stk1.push(c);
        }else if(input == 'L'){
            if(stk1.empty()){
                continue;
            }else{
                char temp = stk1.top();
                stk1.pop();
                stk2.push(temp);
            }
        }else if(input == 'B'){
            if(stk1.empty()){
                continue;
            }else{
                stk1.pop();
            }
        }else if(input == 'D'){
            if(stk2.empty()){
                continue;
            }else{
                char temp = stk2.top();
                stk2.pop();
                stk1.push(temp);
            }
        }
    }
    
    
    while(!stk1.empty()){
        char temp = stk1.top();
        stk1.pop();
        stk2.push(temp);
    }
    
    
    while(!stk2.empty()){
        char temp = stk2.top();
        stk2.pop();
        cout << temp;
    }
    
    
    
}
