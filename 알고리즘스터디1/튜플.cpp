// 50분

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(vector<int>&a, vector<int>&b){
    
    if(a.size() < b.size()){
        return true;
    }else{
        return false;
    }
}

vector<int> solution(string s) {
    vector<int> answer;

    vector<int> temp;
    string str;
    vector<vector<int>> v;
    
    for(int i=1; i<s.size()-1; i++){
        if(48<= s[i] && s[i] <= 57){
            str += s[i];
        }else if(s[i] == ',' && s[i-1] != '}'){
            int num = stoi(str);
            temp.push_back(num);
            str.clear();
        }else if(s[i] == '}'){
            int num = stoi(str);
            temp.push_back(num);
            str.clear();
            v.push_back(temp);
            temp.clear();
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<v.size(); i++){
        
        if(i == 0){
            int num = v[i][0];
            answer.push_back(num);
        }else{
            set<int> s;
            
            for(int j=0; j<v[i-1].size(); j++){
                s.insert(v[i-1][j]);
            }
            
            for(int j=0; j<v[i].size(); j++){
                int num = v[i][j];
                
                if(s.count(num) > 0){
                    continue;
                }else{
                    answer.push_back(num);
                    break;
                }
            }
        }
    }
    
      
    return answer;
}
