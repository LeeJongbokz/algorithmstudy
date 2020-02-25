#include <iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int cnt = 0; 
    
    for(int i=1; i<=N; i++){
        
        if(i % 5 == 0){
            cnt += 1;
        }
        
        if(i % 25 == 0){
            cnt += 1;
        }
        
        if(i % 125 == 0){
            cnt += 1;
        }
    
    }
    
    cout << cnt;
    
    
    
    
}
