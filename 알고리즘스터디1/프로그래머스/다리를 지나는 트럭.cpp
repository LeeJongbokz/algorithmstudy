// 55분

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int len = truck_weights.size();
    
    queue<int> trucks;
    queue<pair<int,int>> truck_time;
    
    for(int i=0; i<truck_weights.size(); i++){
        trucks.push(truck_weights[i]);
    }
    
    int time = 0;
    int total_weight = 0; 
    int cnt = 0;
    
    while(1){
        
        time++;
        
        if(!truck_time.empty()){
            int first_weight = truck_time.front().first;
            int first_time = truck_time.front().second;
            
            if(time - first_time == bridge_length){
                total_weight -= first_weight;
                truck_time.pop();
                cnt += 1;
            }
        }
        
        if(cnt == len){
            break;
        }
        
        if(!trucks.empty() && (weight >= total_weight + trucks.front())){
            truck_time.push(make_pair(trucks.front(), time));
            total_weight += trucks.front();
            trucks.pop();
        }   
    }
    
    answer = time; 
    
    
    return answer;
}
