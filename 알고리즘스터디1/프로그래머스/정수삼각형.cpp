// 20분

#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dp[510][510];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    memset(dp, 0, sizeof(dp));
    
    int len = triangle.size();
    
    dp[0][0] = triangle[0][0];
    
    for(int i=1; i<len; i++){
        for(int j=0; j<=i; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }else if(j == i){
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }else{
                dp[i][j] = triangle[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    
    for(int j=0; j<=len-1; j++){
        answer = max(answer, dp[len-1][j]);
    }
    
    return answer;
}
