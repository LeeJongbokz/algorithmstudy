#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    int sum = 0;
    int len = d.size();
    int cnt = 0; 
    
    sort(d.begin(), d.end());
    
    for(int i=0; i<len; i++){
        sum += d[i];
        cnt += 1;
        if(sum > budget){
            sum -= d[i];
            cnt -= 1;
            break;
        }
    }
    
    answer = cnt;
    
    return answer;
}
