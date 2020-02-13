#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int len = s.length();
    
    for(int i=0; i<len; i++){
        
        if(i == 0){
            if(65<=s[i] && s[i]<=90){
                continue;
            }else if(97<=s[i] && s[i]<=122){
                int num = s[i] - 32;
                s[i] = num;
            }else{
                continue;
            }
        }else{
            if(s[i-1] != ' '){
                if(65<=s[i] && s[i] <= 90){
                    int num = s[i] + 32;
                    s[i] = num;
                }else{
                    continue;
                }
            }else if(s[i-1] == ' '){
                if(97<=s[i] && s[i] <= 122){
                    int num = s[i] - 32;
                    s[i] = num;
                }else{
                    continue;
                }
            }
        }
        
    }
    
    answer = s; 
    
    return answer;
}
