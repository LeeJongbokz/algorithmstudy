#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;

int main(){
    
    string A;
    string B;
    cin >> A >> B;
    
    int lenA = A.length();
    int lenB = B.length();
    
    int dp[1010][1010]={0};
    
    
    for(int i=1; i<=lenA; i++){
        for(int j=1; j<=lenB; j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    
    cout << dp[lenA][lenB];
    
    
    
    
    
    
}
