#include <string>
#include <vector>
#include <algorithm> 
#include <cstring> 
#include <set> 

using namespace std;

bool check[10];
vector<int> v[10];
set<string> s; 

bool isSame(string& a, string& b){
    
    if(a.size() == b.size()){
        
        for(int i=0; i<a.size(); i++){
            if(a[i] == '*'){
                continue;
            }else{
                if(a[i] != b[i]){
                    return false; 
                }
            }
        }
        
        
    }else{
        return false; 
    }
    
    return true; 
    
}

void recursive(int idx, int len){
    
    if(idx == len){

        string temp;
        
        for(int i=0; i<10; i++){
            if(check[i]){
                temp += to_string(i);
            }
        }
        
        s.insert(temp); 
        return; 
    }

    for(int i=0; i<v[idx].size(); i++){
        int pos = v[idx][i];
        if(check[pos]){
            continue;
        }
        check[pos] = true;
        recursive(idx+1, len);
        check[pos] = false; 
        
    }
    
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    int answer = 0;
    
    memset(check, false, sizeof(check));
    
    int len = banned_id.size(); 
   
    for(int i=0; i<banned_id.size(); i++){
        for(int j=0; j<user_id.size(); j++){
            if(isSame(banned_id[i], user_id[j])){
                v[i].push_back(j);
            }
        }
    }
    
    recursive(0, banned_id.size());
    
    answer = s.size(); 
    
    return answer;
}
