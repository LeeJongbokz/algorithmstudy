#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int num, int k, vector<int>& v){
    
    int count = 0; 
    
    for(int i=0; i<v.size(); i++){
        if(v[i] - num <= 0){
            count += 1;
        }else{
            count = 0; 
        }
        
        if(count >= k){
            return true;
        }
    }
    return false; 
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
  int start = 1;
  int end = *max_element(stones.begin(), stones.end());
  int len = stones.size();
    
    while(start<=end){
        int mid = (start+end) / 2;
        if(check(mid, k, stones)){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
 
    answer = start; 
    
    return answer;
}
