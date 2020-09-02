#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int len = prices.size(); 
    int pos = 0; 
    
    while(1){
        
        if(pos == len){
            break; 
        }
        
        int num = prices[pos];
        int cnt = 0; 
        
        for(int i=pos+1; i<len; i++){
            if(num > prices[i]){
                cnt += 1;
                break;
            }else{
                cnt += 1;
            }
        }
        answer.push_back(cnt);
        pos += 1;
    }
    
    return answer;
}
