#include <iostream>

using namespace std;

int main(){
    
    
    int N, K;
    cin >> N >> K;
    
    int arr[1010][1010] = {0};
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<=N; j++){
            if(j ==0 || j==i){
                arr[i][j] = 1;
            }else{
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
                arr[i][j] %=10007;
            }
        }
    }
    
    cout << arr[N][K];
    
    
    
}
