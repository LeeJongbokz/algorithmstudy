#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    int len = land.size();
    
    int maxSum[100010][4] = {0};
    
    maxSum[0][0] = land[0][0];
    maxSum[0][1] = land[0][1];
    maxSum[0][2] = land[0][2];
    maxSum[0][3] = land[0][3];
    
    for(int i=1; i<len; i++){
        maxSum[i][0] = max(maxSum[i-1][1] + land[i][0], maxSum[i-1][2]+land[i][0]);
        maxSum[i][0] = max(maxSum[i][0], maxSum[i-1][3]+land[i][0]);
        
        maxSum[i][1] = max(maxSum[i-1][0] + land[i][1], maxSum[i-1][2]+land[i][1]);
        maxSum[i][1] = max(maxSum[i][1], maxSum[i-1][3]+land[i][1]);
        
        maxSum[i][2] = max(maxSum[i-1][0] + land[i][2], maxSum[i-1][1]+land[i][2]);
        maxSum[i][2] = max(maxSum[i][2], maxSum[i-1][3]+land[i][2]);
        
        maxSum[i][3] = max(maxSum[i-1][0] + land[i][3], maxSum[i-1][1]+land[i][3]);
        maxSum[i][3] = max(maxSum[i][3], maxSum[i-1][2]+land[i][3]);
    }
    
    answer = max(maxSum[len-1][0], maxSum[len-1][1]);
    answer = max(answer, maxSum[len-1][2]);
    answer = max(answer, maxSum[len-1][3]);
    
    return answer;
}
