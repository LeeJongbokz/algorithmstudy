#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int M, N;
    cin >> M >> N;
    
    int cnt = 0; 
    int sum = 0;
    
    vector<int> v;
    
    for(int i=M; i<=N; i++){
        
        if(i == 1){
            continue;
        }
        
        cnt = 0; 
        
        for(int j=2; j<i; j++){
            if(i % j == 0){
                cnt += 1;
                break;
            }
        }
        
        if(cnt == 1){
            continue;
        }else{
            sum += i;
            v.push_back(i);
        }
      
    }
    
    
    if(v.empty()){
        cout << -1;
    }else{
        cout << sum << '\n';
        cout << v[0];
    }
    
    
    
    
    
    
    
}
