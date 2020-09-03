// 60분

#include <string>
#include <vector>
#include <algorithm> 
#include <cstring>

using namespace std;

bool check[510];

bool cmp1(vector<int>&a, vector<int>&b){
    if(a[0] < b[0]){
        return true;
    }else if(a[0] == b[0]){
        return a[1] < b[1];
    }else{
        return false; 
    }
}

bool cmp2(pair<int,int>&a, pair<int,int>&b){
    
    if(a.second > b.second){
        return true;
    }else if(a.second == b.second){
        return a.first< b.first;
    }else{
        return false; 
    }
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    memset(check, false, sizeof(check));
    
    int len = jobs.size();
    int now = 0;
    int total = 0;
    int done = 0; 
    int i = 0; 

    sort(jobs.begin(), jobs.end(), cmp1);
    
    while(1){
        int requestTime = jobs[i][0];
        int duration = jobs[i][1];
        if(requestTime <= now){
            now += duration;
        }else{
            now = requestTime+duration;
        }
        check[i] = true;
        total += (now-requestTime);
        done += 1;
        
        if(done == len){
            break;
        }
        
        vector<pair<int,int>> v;
        
        for(int j=0; j< jobs.size(); j++){
            if(check[j] == false){
                
                int nextRequestTime = jobs[j][0];
                int nextDuration = jobs[j][1];
                
                if(nextRequestTime <= now){
                    v.push_back(make_pair(j, now+nextDuration));
                }
            }
        }
        
        if(v.empty()){
            i += 1;
        }else{
            sort(v.begin(), v.end(), cmp2);
            i = v.back().first; 
        }
        
    }
 
    answer = (int)(total/len); 
    
    return answer;
}
