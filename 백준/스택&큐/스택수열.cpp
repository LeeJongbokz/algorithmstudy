#include <iostream>
#include <stack>
#include <vector> 

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int input = 1;
    int index = 0;
    
    stack<int> stk;
    vector<char> v;
    
    vector<int> arr;
    
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    while(1){
        
        if(!stk.empty() && arr[index] == stk.top()){
            stk.pop();
            index += 1;
            v.push_back('-');
        }else{
            if(input == (n+1)){
                break;
            }
            stk.push(input);
            input+=1;
            v.push_back('+');
        }
        
        if(index == n){
            break;
        }
        
    }
    
    
    if(stk.empty()){
        for(int i=0; i< v.size(); i++){
            cout << v[i] << '\n';
        }
    }else{
        cout << "NO" << '\n';
    }
    
    
 
    
}
