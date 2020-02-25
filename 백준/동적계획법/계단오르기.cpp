#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int dp[310];
    int arr[310];
    
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    
    
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    
    for(int i=3; i<=N; i++){
        dp[i] = max(arr[i] + arr[i-1] + dp[i-3], arr[i]+dp[i-2]);
    }
    
    cout << dp[N];
    
 
    
}
