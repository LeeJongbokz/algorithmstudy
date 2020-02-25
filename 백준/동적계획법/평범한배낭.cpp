#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    
    int arr[110][100010]={0};
    int w[110]={0};
    int v[110]={0};
    
    int N,K;
    cin >> N >> K;
    
    for(int i=1; i<=N; i++){
        int W, V;
        cin >> W >> V;
        w[i] = W;
        v[i] = V;
    }
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<=K; j++){
            arr[i][j] = arr[i-1][j];
            
            if( j-w[i] >= 0){
                arr[i][j] = max( arr[i-1][j-w[i]] + v[i], arr[i][j] );
            }
            
        }
    }
    
    cout << arr[N][K];
    
    
    
    
}
