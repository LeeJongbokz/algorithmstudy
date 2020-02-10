#include <string>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

int solution(vector<int> priorities, int location) {
    
    queue<pair<int, int>> q;
    vector<int> v;
    
    int len = priorities.size();
    
    for(int i=0; i<len; i++){
        int num = priorities[i];
        q.push(make_pair(i, num));
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    int num = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int z = v.back();
        
        if(y == z){
            if(x == location){
                break;
            }else{
                num += 1;
                v.pop_back();
            }
        }else{
            q.push(make_pair(x,y));
        }
    }
    
    int answer;
    
    answer = num;
    
    return answer;
       
    
}
