#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    int len = phone_book.size();
    
    for(int i=0; i<len; i++){
        int len1 = phone_book[i].length();
        
        for(int j=i+1; j<len; j++){
            
            int len2 = phone_book[j].length();
            
            if(len1 <= len2){
                string cmp = phone_book[j].substr(0, len1);
                if(phone_book[i] == cmp){
                    answer = false;
                    break;
                }
            }else if(len1 > len2){
                string cmp = phone_book[i].substr(0, len2);
                if(phone_book[j] == cmp){
                    answer = false;
                    break;
                }
            }
        }
        
        if(answer == false){
            break;
        }
    }
    

    return answer;
    
    
}
