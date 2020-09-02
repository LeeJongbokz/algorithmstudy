// 20분

#include <string>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int,int>> documents;
    vector<int>v;
    
    for(int i=0; i<priorities.size(); i++){
        documents.push(make_pair(priorities[i], i));
        v.push_back(priorities[i]);
    }
    
    sort(v.begin(), v.end());
    int cnt = 0; 
    
    while(1){
        
        int first_priorities = documents.front().first;
        int first_pos = documents.front().second;
        documents.pop();
        
        if(first_priorities == v.back()){
              cnt += 1;
              
              if(first_pos == location){
                  break;   
              }else{
                  v.pop_back();
                  continue;
              }
        }else{
            documents.push(make_pair(first_priorities, first_pos));
        }
        
        
    }
    
    answer = cnt; 
    
    return answer;
}
