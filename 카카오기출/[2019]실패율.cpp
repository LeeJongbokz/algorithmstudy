#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

bool cmp(pair<int, double> a, pair<int,double> b){
    
    if(a.second > b.second){
        return true;
    }else if(a.second == b.second){
        if(a.first < b.first){
            return true;
        }else{
            return false;
        }
    }else{
        return false; 
    }
    
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<pair<int, double>> result;
    
    int len = stages.size();
    int total = len;
    
    for(int i=1; i<=N; i++){
        int cnt = 0; 
        
        for(int j=0; j<len; j++){
            if(i == stages[j]){
                cnt += 1;
            }
        }
        
        double failureRate;
        
        if(total == 0){
            failureRate = 0; 
        }else{
            failureRate = (double)cnt / (double)total;
        }
        result.push_back(make_pair(i, failureRate));
        total -= cnt;
    }
    
    sort(result.begin(), result.end(), cmp);
    
    int resultlen = result.size();
    
    for(int i=0; i<resultlen; i++){
        answer.push_back(result[i].first);
    }
    
    return answer;
}
