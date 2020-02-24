#include <iostream> 

using namespace std;

int main(){
    
    int M,N;
    cin >> M >> N;
    
    int arr[1000010] = {0};
    
    for(int i=2; i<=1000000; i++){
        arr[i] = i;
    }
    
    for(int i=2; i<=1000000; i++){
        if(arr[i] == 0){
            continue;
        }
        
        for(int j=i+i; j<=1000000; j+=i){
            if(arr[j] != 0){
                arr[j] = 0;
            }
        }
    }
    
    for(int i=M; i<=N; i++){
        if(arr[i] != 0){
            cout << arr[i] << '\n';
        }
    }
    
    
    
    
    
}
