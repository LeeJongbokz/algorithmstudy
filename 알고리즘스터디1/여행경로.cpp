#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool check[10010];

vector<string> answer;

bool cmp(vector<string>&a, vector<string>&b){
    
    bool change = false;
    
    for(int i=0; i<a.size(); i++){
        string tempA = a[i];
        string tempB = b[i];
        
        if(tempA > tempB){
            change = true;
            break;
        }else if(tempA < tempB){
            change = false;
            break;
        }
       
    }
    
    return change; 
}


void recursive(int cnt, int len, string current, vector<string>&v, vector<vector<string>> tickets){
    
    if(cnt == len){
        if(answer.empty()){
            for(int i=0; i<v.size(); i++){
                answer.push_back(v[i]);
            }
        }else{
      
            bool change = false;
            
            change = cmp(answer, v);
            
            if(change == true){
                answer.clear();
                
                for(int i=0; i<v.size(); i++){
                    answer.push_back(v[i]);
                }
            }  
        }
        return; 
    }
    
    for(int i=0; i<len; i++){
        if(check[i] == false &&tickets[i][0] == current){
            check[i] = true;
            v.push_back(tickets[i][1]);
            recursive(cnt+1, len, tickets[i][1], v, tickets);
            v.pop_back();
            check[i] = false;
        }
    }
}



vector<string> solution(vector<vector<string>> tickets) {
 
    memset(check, false, sizeof(check));
    
    int len = tickets.size();
    vector<string> v;
    string current = "ICN";
    v.push_back(current);
    
    recursive(0, len, current, v, tickets);
    
    return answer;
}
