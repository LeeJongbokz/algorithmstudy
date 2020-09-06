// 50분

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int cnt = 0; 
 
    for(int i=0; i<number.size(); ){
         
        if(cnt == k){
            break;
        }
        
        if(i == 0){
            i += 1;
            continue;
        }else{
            char a = number[i-1];
            char b = number[i];
            
            if(a < b){
                number.erase(i-1, 1);
                i -= 1;
                cnt += 1;
                
            }else{
                i += 1; 
            }
        }
    }
        
    while(cnt < k){
        number.pop_back();
        cnt += 1;
    }    
               
 
    answer = number;
    
    return answer;
}
