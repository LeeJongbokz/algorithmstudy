#include <iostream>

using namespace std;

int main(){
    
    int arr[300010]= {0};
    
    for(int i=2; i<=300000; i++){
         arr[i] = i;
    }
    
    for(int i=2; i<=300000; i++){
        if(arr[i] == 0){
            continue;
        }
        
        for(int j=i+i; j<=300000; j+=i){
            if(arr[j] != 0){
                arr[j] = 0; 
            }
        }
    }
    
    int cnt = 0;
    
    while(1){
        
        cnt = 0; 
        
        int num;
        cin >> num;
        
        if(num == 0){
            break; 
        }
        
        for(int i=num+1; i<=2*num; i++){
            if(arr[i] != 0){
                cnt += 1;
            }
        }
        
        cout << cnt << '\n';
        
    }
    
    
    
    
    
    
    
    
    
    
    
}
