// 30분

#include <cctype>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string> v;
    
    int cacheLeft = cacheSize; 
    
    for(int i=0; i<cities.size(); i++){
          
            bool isExist = false; 
            string str = cities[i];
            for(int j=0; j<str.size(); j++){
                str[j] = toupper(str[j]);
            }
        
            if(v.size() != 0){
                for(int j=0; j< v.size(); j++){
                    if(str == v[j]){
                        answer += 1;
                        v.erase(v.begin()+j);
                        v.push_back(str);
                        isExist = true;
                        break; 
                    }
                }
                if(isExist == true){
                    continue; 
                }        
            }   
        
            if(cacheLeft > 0){
                v.push_back(str);
                cacheLeft -= 1;
                answer += 5;
            }else if(cacheLeft == 0){
                if(v.size() != 0){
                  v.erase(v.begin());
                  v.push_back(str);
                }
                answer += 5; 
            }
        
    }
    
    
    return answer;
}
