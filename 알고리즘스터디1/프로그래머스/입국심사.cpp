// 30분

#include <string>
#include <vector>

using namespace std;

const long long INF = 999999999999999;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long start = 1;
    long long end = times.back()*(long long)n;
    long long minTime = INF;
    
    while(start <= end){
        long long mid = (start+end)/2;
        long long total = 0;
        
        for(int i=0; i<times.size(); i++){
            total += (mid/(long long)times[i]);
        }
        
        if(n<= total){
            if(minTime>=mid){
                minTime = mid;
            }
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    
    answer = minTime;
    
    return answer;
}
