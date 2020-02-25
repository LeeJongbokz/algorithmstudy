#include <iostream>

using namespace std;

int main(){
    
    int N, K;
    cin >> N >> K;
    
    int arr[20][20]={0};
    
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<=N; j++){
            if(j==0 || j==i){
                arr[i][j] = 1;
            }else{
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }
    
    
    cout << arr[N][K];
    
    
    
}
