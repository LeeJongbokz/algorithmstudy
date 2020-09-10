// 40분

#include <string>
#include <stack>
#include <cmath> 

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    stack<int> stk;
    stack<int> temp; 
    
    for(int i=0; i<dartResult.size(); ){
        
        if('0' <= dartResult[i] && dartResult[i]<='9'){
            if(dartResult[i+1] == '0'){
                
                char c = dartResult[i+2];
                int num = 10;
                
                if(c == 'D'){
                    num = pow(num,2);
                }else if(c == 'T'){
                    num = pow(num,3);
                }
                stk.push(num);
                i += 3;
                
            }else{
                
                char c = dartResult[i+1];
                int num = dartResult[i] - '0';
                
                if(c == 'D'){
                    num = pow(num,2);
                }else if(c == 'T'){
                    num = pow(num,3);
                }
                stk.push(num);
                i+=2;
                
            }
        }else if(dartResult[i] == '*'){
            
            int cnt = 0;
            
            while(!stk.empty()){
                if(cnt == 2){
                    break;
                }
                int num = stk.top();
                stk.pop();
                num = 2*num;
                temp.push(num);
                cnt += 1;
            }
            
            while(!temp.empty()){
                int num = temp.top();
                temp.pop();
                stk.push(num);
            }
            
            i += 1;
        }else if(dartResult[i] == '#'){
            
            int num = stk.top();
            stk.pop();
            num = -num;
            stk.push(num);
            
            i+= 1;
        }
        
    }
    
    while(!stk.empty()){
        int num = stk.top();
        stk.pop();
        answer += num;
    }
    
    
    
    return answer;
}
