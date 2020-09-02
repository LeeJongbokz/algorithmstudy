// 15분

#include <string>
#include <vector>
#include <map> 

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    
    for(int i=0; i<clothes.size(); i++){
        
        string temp = clothes[i][1];
        
        if(m.count(temp) > 0){
            m[temp] += 1;
        }else{
            m.insert(pair<string,int>(temp, 1));
        }
        
    }
    
    map<string,int>::iterator iter;
 
    if(m.size() >= 2){
        for(iter=m.begin(); iter!=m.end(); iter++){
            answer *= (iter->second+1);
        }
        answer -= 1;
    }else{
        for(iter=m.begin(); iter!=m.end(); iter++){
            answer = iter->second;
        }
    }
   
   
    return answer;
}
