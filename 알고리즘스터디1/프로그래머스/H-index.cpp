#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    int h = 0;
    int result = 0; 
    sort(citations.begin(), citations.end());
    
    while(1){
       int cnt = 0;
        
        for(int i=0; i<citations.size(); i++){
            if(citations[i]>=h){
                cnt += 1;
            }else{
                continue;
            }
        }
        
        if(cnt >= h){
            result = h;
            h += 1;
            continue;
        }else{
            break;
        }
        
    }
    
    answer = result; 
    
    return answer;
}
