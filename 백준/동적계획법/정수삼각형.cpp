#include <iostream>
#include <algorithm> 

using namespace std;

int main(){
  
    int n;
    cin >> n;
    
    int a[510][510] = {0};
    int maxSum[510][510] = {0};
    
    for(int i=1; i<=n; i++){
        
        for(int j=1; j<=i; j++){
            int num;
            cin >> num;
            a[i][j] = num;
        }
    }
    
    
    maxSum[1][1] = a[1][1];
    
    for(int i=2; i<=n; i++){
        
        for(int j=1; j<=i; j++){
            if(j == 1){
                maxSum[i][j] = a[i][j] + maxSum[i-1][j];
            }else if(j == i){
                maxSum[i][j] = a[i][j] + maxSum[i-1][j-1];
            }else{
                maxSum[i][j] = max(a[i][j]+maxSum[i-1][j-1], a[i][j]+maxSum[i-1][j]);
            }
        }
    }
    
    int maxNum = max(maxSum[n][1], maxSum[n][2]);
    
    for(int i=3; i<=n; i++){
        maxNum = max(maxNum, maxSum[n][i]);
    }
   
    cout << maxNum;
    

    
}
