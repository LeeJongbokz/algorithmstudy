#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector<int> answer;
    
    while(1){
        
        if(progresses.empty()){
            break;
        }
        
        int len = progresses.size();
        
        while(1){
            
            for(int i=0; i<len; i++){
                progresses[i] += speeds[i];
            }
            
            if(progresses[0] >= 100){
                break;
            }
            
        }
        
        int cnt = 0; 
        
        for(int i=0; i<len; i++){
            if(progresses[i] >= 100){
                cnt += 1;
            }else{
                break;
            }
        }
        
        progresses.erase(progresses.begin(), progresses.begin()+cnt);
        speeds.erase(speeds.begin(), speeds.begin()+cnt);
        
        answer.push_back(cnt);
        
    }
    
    
    return answer;
}
