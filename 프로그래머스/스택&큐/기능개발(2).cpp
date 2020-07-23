#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    while(1){
        
        int cnt = 0; 
        
        if(progresses.empty()){
            break;
        }
        
        for(int i=0; i<progresses.size(); i++){
               progresses[i] += speeds[i];
        }
        
        for(int i=0; i<progresses.size(); i++){
            if(progresses[i]>=100){
                cnt += 1;
            }else{
                break;
            }
        }
    
        for(int i=0; i<cnt; i++){
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
        }
        
        if(cnt != 0){
            answer.push_back(cnt);
        }
    }
    
    
    return answer;
}
