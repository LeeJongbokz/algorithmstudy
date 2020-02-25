#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int num = 0;
    int result = 0; 
    
    vector<int> v;
    
    for(int i=1; i<N; i++){
        
        num = 0;
        result = 0;
        
        num = i;       
        result += num;
        
        while(1){
            int d = num % 10;
            result += d;
            num /= 10;
            if(num == 0){
                break;
            }
        }
        
        if(result == N){
            v.push_back(i);
            break;
        }
        
    }
    
    
    if(v.empty()){
        cout << 0;
    }else{
        cout << v[0];
    }
    
}
