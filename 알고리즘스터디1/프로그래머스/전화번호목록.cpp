// 10분

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    int len = phone_book.size(); 
    
    for(int i=0; i<len-1; i++){
        string A = phone_book[i];
        string B = phone_book[i+1];
        string C = B.substr(0, A.size());
        
        if(A == C){
            answer = false;
            break;
        }    
    }
    
    return answer;
}
