class Solution {
public:
    bool isValid(string s) {
        
        const string opening("({[");
        const string closing(")}]");
        
        stack<char> openStack;
        
        for(int i=0; i< s.size(); i++){
            
            if(opening.find(s[i]) != -1){
                openStack.push(s[i]);
            }else{
                
                if(openStack.empty()){
                    return false;
                }
                
                if(opening.find(openStack.top()) != closing.find(s[i])){
                    return false;
                }
                
                openStack.pop();
                
            }
            
        }
        
        return openStack.empty();
        
        
    }
};
