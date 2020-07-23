#include <string>
#include <vector>
#include <stack> 
#include <algorithm> 

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    stack<int> stk;
    
    for(int i=0; i<heights.size(); i++){
        stk.push(heights[i]);
    }
    
    while(1){
        
        if(stk.empty()){
            break;
        }
        
        int top = stk.top();
        stk.pop();
        
        stack<int> temp;
        
        while(1){
            
            if(stk.empty()){
                answer.push_back(0);
                break;
            }
            
            if(top < stk.top()){
                answer.push_back(stk.size());
                break;
            }else{
                int num = stk.top();
                stk.pop();
                temp.push(num);
            }            
        }
        
        while(!temp.empty()){
            int num = temp.top();
            temp.pop();
            stk.push(num);
        }
        
        
    }
    
    
    reverse(answer.begin(), answer.end());   
    
    return answer;
}
