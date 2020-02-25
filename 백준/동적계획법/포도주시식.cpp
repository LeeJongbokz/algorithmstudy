#include <iostream>
#include <algorithm> 

using namespace std;

int main(){
    
    int dp[10010][3]={0};
    int MAXNUM;
    
    int A[10010]={0};
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }
    
    for(int i=1; i<=n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][0] = max(dp[i][0], dp[i-1][2]);
        dp[i][1] = dp[i-1][0] + A[i];
        dp[i][2] = dp[i-1][1] + A[i];
    }
    
    MAXNUM = max(dp[n][0], dp[n][1]);
    MAXNUM = max(MAXNUM, dp[n][2]);
    
    cout << MAXNUM;
    
    
    
}
