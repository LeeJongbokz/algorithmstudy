// 80분

#include <string>
#include <vector>
#include <map> 
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter){
    vector<string> internal;
    stringstream ss(str);
    string temp;
    
    while(getline(ss, temp, delimiter)){
        internal.push_back(temp);
    }
    
    return internal; 
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<pair<string, string>> list;
    map<string, string> m;
    
    for(int i=0; i<record.size(); i++){
        
        vector<string> v = split(record[i], ' ');
        if(record[i][0] == 'E'){
            list.push_back(make_pair(v[0], v[1]));
        
        if(m.count(v[1]) > 0){
            m[v[1]] = v[2];
        }else{
            m.insert(pair<string,string>(v[1], v[2]));
        }
        }else if(record[i][0] == 'L'){
            list.push_back(make_pair(v[0], v[1]));
        }else if(record[i][0] == 'C'){
            m[v[1]] = v[2]; 
        }
    }
    
    for(int i=0; i<list.size(); i++){
        string order = list[i].first;
        string id = list[i].second;
        string nickname;
        string sentence;
        
        nickname = m[id];
        
        if(order == "Enter"){
            sentence += nickname;
            sentence += "님이 ";
            sentence += "들어왔습니다.";
        }else if(order == "Leave"){
            sentence += nickname;
            sentence += "님이 ";
            sentence += "나갔습니다.";
        }
        answer.push_back(sentence); 
    }
    
    return answer;
}
