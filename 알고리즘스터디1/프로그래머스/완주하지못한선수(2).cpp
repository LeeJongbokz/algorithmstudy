// 10분

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
 
    map<string,int> m1;
    map<string,int> m2;
    
    for(int i=0; i<participant.size(); i++){
        string  temp = participant[i];
        
        if(m1.count(temp) > 0){
            m1[temp] += 1;
        }else{
            m1.insert(pair<string,int>(temp, 1));
        }   
    }
    
    for(int i=0; i<completion.size(); i++){
        string temp = completion[i];
        
        if(m2.count(temp) > 0){
            m2[temp] += 1;
        }else{
            m2.insert(pair<string,int>(temp, 1));
        }
    }
    
    map<string,int>::iterator iter;
    
    for(iter=m1.begin(); iter!=m1.end(); iter++){
    
        string search = iter->first;
        
        if(m1.count(search) > 0){
            
            if(m1[search] != m2[search]){
                answer = search;
                break;
            }
            
        }else{
            answer = search;
            break;
        }
        
    }
    
    
    
    return answer;
}
