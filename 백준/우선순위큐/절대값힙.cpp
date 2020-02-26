#include <iostream>
#include <queue> 

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    // 최소 힙(양수 입력)
    priority_queue<int, vector<int>, greater<int>> pq1;
    
    // 최대 힙(음수 입력)
    priority_queue<int> pq2;
    
    
    while(N--){
        
        int num;
        cin >> num;
        
        if(num > 0){
            pq1.push(num);
        }else if(num < 0){
            pq2.push(num);
        }else if(num == 0){
            if(pq1.empty() && pq2.empty()){
                cout << 0 << '\n';
            }else if(pq1.empty() && !pq2.empty()){
                cout << pq2.top() << '\n';
                pq2.pop();
            }else if(!pq1.empty() && pq2.empty()){
                cout << pq1.top() << '\n';
                pq1.pop();
            }else if(!pq1.empty() && !pq2.empty()){
                int a = pq1.top();
                int b = -pq2.top();
                
                if(a < b){
                    cout << pq1.top() << '\n';
                    pq1.pop();
                }else if(a > b){
                    cout << pq2.top() << '\n';
                    pq2.pop();
                }else if(a == b){
                    cout << pq2.top() << '\n';
                    pq2.pop();
                }
            }
        }
        
    }
    
    

    
}








