#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
    
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); 을 해주는 이유는
    // C++ iostream을 C의 stdio와 동기화해주기 위함이다
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // 연산의 개수 N을 변수 N에 입력한다 
    int N;
    cin >> N;
    
    // priority_queue<int> pq를 선언한다
    // 이는 #include <queue>가 전제되어야 한다
    // Priority_queue는 입력되는 값을 특정 순서(오름차순 or 내림차순)에 따라 저절로 배열해주는 큐를 의미한다.
    // 이 경우는 최대 우선순위 큐를 의미함
    // 최소 우선순위 큐는 priority_queue<int, vector<int>, greater<int>> pq; 로 선언함
    // 이렇게 선언하는 이유는 priority_queue에 속한 값을 벡터의 값으로 인식해서, 내림차순으로 나열하기 때문임
    // 내림차순으로 나열하면 제일 끝에 있는 원소(pq.top())가 제일 작은 원소가 됨 
    priority_queue<int> pq;
    
    // while문을 N번 순회하면서 
    // 정수 x를 입력한다 
    while(N--){
        int x;
        cin >> x;
        
        // 정수 x가 0일 때는, pq에서 가장 큰 값을 출력한다. 
        if(x == 0){
            // pq가 비어있을 때는 0을 출력함 
            if(pq.empty()== true){
                cout << 0 << '\n';
            // pq가 비어있지 않을 때는, pq.top()을 출력함
            // pq.top()을 출력하는 이유는 pq.top()이 pq에서 가장 큰 값이기 때문임
            }else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        // 정수 x가 0이 아닐 때는, pq에 새로운 값을 추가함 
        else{
            pq.push(x);
        }
         
    }
    
 
   
    
    
}
