#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
    
    // 출력 시간을 줄여주기 위해서
    // 아래와 같은 표현을 사용함 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // 최소 우선순위 큐를 선언함
    // 최소 우선순위 큐는 priority_queue<int, vector<int>>, greater<int>> pq; 로 선언함
    // 최소 우선순위 큐는 #include <queue>를 해줘야 함 
    priority_queue<int, vector<int>, greater<int>> pq;
    
    
    // N개의 수에 대해서 
    int N;
    cin >> N;
    
    // while문을 N번 순회를 하면서 
    while(N--){
        
        // x가 입력되면 
        int x;
        cin >> x;
        
        // x가 0일 때는 
        if(x == 0){
            
            // pq가 비어 있다면, 0을 출력함
            if(pq.empty()== true){
                cout << 0 << '\n';
            }
            // pq가 비어 있지 않다면, 가장 작은 값
            // 즉, pq.top()을 출력함 
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        // x가 0이 아닐 때는, 해당 수를 우선순위 큐 pq에 넣어줌 
        else{
            pq.push(x);
        }        
        
    }
    
    
    
}










