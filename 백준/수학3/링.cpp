#include <iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int arr[110]={0};
    
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    
    
    for(int i=2; i<=N; i++){
        int a = arr[1];
        int b = arr[i];
        int gcd;
        
        while(1){
            int r = a % b;
            
            if(r == 0){
                gcd = b;
                break;
            }
            
            a = b;
            b = r;   
        }
        
        cout << arr[1]/gcd << '/' << arr[i]/gcd << '\n';
        
    }
    
    
    
    
    
    
    
}
