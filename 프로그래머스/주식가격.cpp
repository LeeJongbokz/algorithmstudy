#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    vector<int> answer;
    stack<int> stk1;
    stack<int> stk2;
    
    int len = prices.size();
 
    for(int i=len-1; i>=0; i--){
        stk1.push(prices[i]);
    } 
    
    for(int i=0; i<len; i++){
        
          int x = stk1.top();
          stk1.pop();
        
          int t = 0;
        
          if(i != len-1){
             
            while(1){
             if(x > stk1.top()){
                  t++;
                  break; 
             }else if( x <= stk1.top()){
                 int y = stk1.top();
                 stk1.pop();
                 stk2.push(y);
                 t++;
                 if(t == (len-1)-i){
                     break;
                 }
             }
            }   
         }else if(i == len-1){
              t = 0;
         }
        
         while(!stk2.empty()){
             int z = stk2.top();
             stk2.pop();
             stk1.push(z);
         }
        
         answer.push_back(t);
        
    }
            
    return answer;
        
}
