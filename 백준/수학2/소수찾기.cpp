#include <iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int arr[1010] = {0};
    
    for(int i=2; i<=1000; i++){
        arr[i] = i;
    }
    
    for(int i=2; i<=1000; i++){
        if(arr[i] == 0){
            continue;
        }
        
        for(int j=i+i; j<=1000; j+=i){
            if(arr[j] != 0){
                arr[j] = 0;
            }
        }
        
    }
    
    
    int cnt = 0;
    
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        if(arr[num] != 0){
            cnt += 1;
        }
    }
    
    cout << cnt;
    
}
