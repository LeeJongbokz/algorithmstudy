#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    queue<int> q;
    
    for(int i=1; i<=N; i++){
        q.push(i);
    }
    
    if(N == 1){
        cout << 1 << '\n';
        return 0;
    }else{
    
        while(1){
            q.pop();
        
            if(q.size() == 1){
                break;
            }
        
            int x = q.front();
            q.pop();
            q.push(x);
       
        }
    }
    
    cout << q.front() << '\n';
    
  
}
