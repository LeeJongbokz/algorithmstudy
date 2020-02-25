#include <iostream>
#include <stack>

using namespace std;

int main(){
    
    int K;
    cin >> K;
    
    stack<int> stk;
    
    for(int i=1; i<=K; i++){
        int num;
        cin >> num;
        
        if(num != 0){
            stk.push(num);
        }else if(num == 0){
            stk.pop();
        }

    }

    int sum = 0;
    
    while(!stk.empty()){
        int num = stk.top();
        sum += num;
        stk.pop();
    }
    
    cout << sum;
    
    
    
    
}
