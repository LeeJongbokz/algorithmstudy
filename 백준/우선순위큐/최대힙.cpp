#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    priority_queue<int> pq;
    
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
