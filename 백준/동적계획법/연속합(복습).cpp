#include <iostream>
#include <algorithm> 

using namespace std;

int main(){
    
    int dp[100010];
    int a[100010];
    
    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++){
        int num;
        cin >> num;
        a[i] = num;
    }
    
    dp[1] = a[1];
    
    for(int i=2; i<=N; i++){
        dp[i] = max(a[i], dp[i-1]+a[i]);
    }
    
    int maxSum = 0; 
    maxSum = dp[1];
    
    for(int i=2; i<=N; i++){
        maxSum = max(maxSum, dp[i]);
    }
    
    cout << maxSum; 
    
    
    
}
