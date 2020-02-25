#include <iostream>
#include <vector>

using namespace std; 

int main(){
    
    int N;
    cin >> N;
    
    int cnt = 0;
    int i = 666;
    int num = 0; 
    
    vector<int> v;
    
    while(1){
        
        cnt = 0;
        num = i; 
        
        while(1){
           int r = num % 10;
           
           if(r == 6){
               cnt += 1;
           }else{
               cnt = 0;
           }
           
           if(cnt == 3){
               v.push_back(i);
               break;
           }
            
           num /= 10;
            
           if(num == 0){
               break;
           } 
            
        }
        
        if(v.size() == N){
            break;
        }
        
        i+=1;
        
    }
    
    cout << v.back();
    
    
 
    
    
}
