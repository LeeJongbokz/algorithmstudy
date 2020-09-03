// 20분

#include <string>
#include <vector>
#include <queue> 

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    int cnt = 0; 
    bool find = false;
    
    while(1){
        int num1 = pq.top();
        pq.pop();
        
        if(num1 >= K){
            find = true;
            break;
        }
        if(pq.empty()){
            break;
        }
        
        int num2 = pq.top();
        pq.pop();
        int new_num = num1+(num2*2);
        pq.push(new_num);
        cnt += 1; 
        
    }
    
    if(find == true){
        answer = cnt;
    }else{
        answer = -1; 
    }
    
    
    return answer;
}
