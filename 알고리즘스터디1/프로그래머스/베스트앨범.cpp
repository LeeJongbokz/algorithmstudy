// 30분

#include <string>
#include <vector>
#include <map>
#include <algorithm> 

using namespace std;

bool cmp(pair<string,int>&a, pair<string,int>& b){
    if(a.second < b.second){
        return true;
    }else{
        return false; 
    }
}

bool cmp2(pair<int,int>&a, pair<int,int>&b){
    if(a.second < b.second){
        return true;
    }else if(a.second == b.second){
        if(a.first > b.first){
            return true;
        }else{
            return false;
        }
    }else{
        return false; 
    }
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string,int> m;
    vector<pair<string, int>> v;
    
    for(int i=0; i<genres.size(); i++){
        string temp = genres[i];
        
        if(m.count(temp) > 0){
            m[temp] += plays[i];
        }else{
            m.insert(pair<string,int>(temp, plays[i]));
        }
    }
    
    map<string,int>::iterator iter;
    
    for(iter=m.begin(); iter != m.end(); iter++){
          v.push_back(make_pair(iter->first, iter->second));
    }
    
    sort(v.begin(), v.end(), cmp);
    
    while(1){
        
        if(v.empty()){
            break; 
        }
        
        string mostGenre = v.back().first; 
        v.pop_back();
        vector<pair<int,int>> v2;
        
        for(int i=0; i<genres.size(); i++){
            if(mostGenre == genres[i]){
                v2.push_back(make_pair(i, plays[i]));
            }
        }
        
        sort(v2.begin(), v2.end(), cmp2);

        if(v2.size() >= 2){
            int pos = v2.back().first;
            answer.push_back(pos);
            v2.pop_back();
            pos = v2.back().first;
            answer.push_back(pos);
        }else{
            int pos = v2.back().first;
            answer.push_back(pos);
        }
        
    }    
    
    
    return answer;
}
