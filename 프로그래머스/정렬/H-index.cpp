#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());
    
    int len = citations.size();
    int start = citations[0];
    
    for(int i=start; i>=0; i--){
        int num = 0;
        
        for(int j=0; j<len; j++){
            if(citations[j] >= i){
                num += 1;
            }
        }
        
        if(num >= i){
            answer = i; 
            break;
        }
        
    }
    
    return answer;
}
