#include <string>
#include <vector>
#include <stack> 
#include <algorithm> 

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    
    int len = heights.size();
    
    stack<int> stk1;
    stack<int> stk2;
    
    for(int i=0; i<len; i++){
        stk1.push(heights[i]);
    }
    
    
    for(int i=1; i<=len; i++){
        
         int x = stk1.top();
         stk1.pop();
    
        while(!stk1.empty()){
        
            if(stk1.top() > x){
                 answer.push_back(stk1.size());
                 break;
            }else{
                int y = stk1.top();
                stk1.pop();
                stk2.push(y);
             }
         }
        
         if(stk1.empty()){
             answer.push_back(0);
         }
    
         while(!stk2.empty()){
             int z = stk2.top();
             stk2.pop();
             stk1.push(z);
         }
        
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
