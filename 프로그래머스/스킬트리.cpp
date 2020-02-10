#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    int len = skill_trees.size();
    
    for(int i=0; i<len; i++){
        string temp = skill_trees[i];
        string str;
        
        for(int j=0; j< temp.length(); j++){
            for(int k=0; k < skill.length(); k++){
                if(temp[j] == skill[k]){
                    str += temp[j];
                }
            }
        }
        
        int strlen = str.length();
        int skilllen = skill.length();
    
        if(skill.substr(0, strlen) == str){
                 answer += 1;
        }
        
        
    }
    
    return answer;
}
