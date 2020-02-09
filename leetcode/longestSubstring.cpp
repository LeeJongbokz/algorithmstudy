#include <algorithm> 


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = (int)s.size();
        int longest = 0; 
        
        for(int i=0; i<len; i++){
            string temp;
            
            
            for(int j=i; j<len; j++){
                if(temp.empty()){
                    temp.push_back(s[j]);
                }else{
                    bool isExist = false; 
                    for(int k=0; k<(int)temp.size(); k++){
                        if(s[j] == temp[k]){
                            isExist = true;
                            break;
                        }
                    }
                    
                    if(isExist == false){
                        temp.push_back(s[j]);
                    }else{
                        break;
                    }
                    
                    
                }        
            }
            
            longest = max(longest, (int)temp.size());
            
        }
        
        return longest;
        
    }
};
