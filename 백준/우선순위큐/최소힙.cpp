#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int N;
    cin >> N;
    
    while(N--){
        
        int x;
        cin >> x;
        
        if(x == 0){
            if(pq.empty()== true){
                cout << 0 << '\n';
            }else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }else{
            pq.push(x);
        }        
        
    }
    
    
    
}










