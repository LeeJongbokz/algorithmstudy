#include <iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    int arr[10010] = {0};
    
    for(int i=2; i<=10000; i++){
        arr[i] = i;
    }
    
    for(int i=2; i<=10000; i++){
        if(arr[i] == 0){
            continue;
        }
        
        for(int j=i+i; j<=10000; j+=i){
            if(arr[j] != 0){
                arr[j] = 0;
            }
        }
    }
    
    for(int i=1; i<=T; i++){
        
        int n;
        cin >> n;
        
        int num1 = n/2;
        
        for(int i=num1; i>=2; i--){
            int j = n-i;
            
            if(arr[i] != 0 && arr[j] != 0){
                cout << i << " " << j << '\n';
                break;
            }
        }  
    }
   
    
}
