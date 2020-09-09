#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;

    int dp[1000010];
    int dp2[1000010];
    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    
    int len = money.size();
    dp[0] = money[0];
    dp[1] = money[0];
    
    for(int i=2; i<len-1; i++){
        dp[i] = max(dp[i-2]+money[i], dp[i-1]);
    }
    
    dp2[0] = 0;
    dp2[1] = money[1];
    
    for(int i=2; i<len; i++){
        dp2[i] = max(dp2[i-2]+money[i], dp2[i-1]);
    }
    
    
    for(int i=0; i<len-1; i++){
        answer = max(answer, dp[i]);
    }
    
    for(int i=0; i<len; i++){
        answer = max(answer, dp2[i]);
    }
    
    
    
    return answer;
}
