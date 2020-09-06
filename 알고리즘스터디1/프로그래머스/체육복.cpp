// 45분

#include <string>
#include <vector>
#include <cstring> 
#include <algorithm> 

using namespace std;

bool check[100];
bool lostCheck[100];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    memset(check, false, sizeof(check));
    memset(lostCheck, false, sizeof(lostCheck));
 
    int able = n-lost.size();
 
    for(int i=0; i<lost.size(); i++){
        int num = lost[i];
        for(int j=0; j<reserve.size(); j++){
            if(num == reserve[j]){
                check[reserve[j]] = true; 
                lostCheck[num] = true; 
                able += 1;
            }
        }
    }
    
    
    for(int i=0; i<lost.size(); i++){
        int num = lost[i];
        if(lostCheck[num] == true){
            continue; 
        }
        
        for(int j=0; j<reserve.size(); j++){
            if(num - reserve[j] == 1 && check[reserve[j]] == false){
                able += 1;
                check[reserve[j]] = true;
                break;
            }
            
            if(num - reserve[j] == -1 && check[reserve[j]] == false){
                able += 1;
                check[reserve[j]] = true;
                break; 
            }
            
        }
    }
    
    answer = able;    
    
    return answer;
}
