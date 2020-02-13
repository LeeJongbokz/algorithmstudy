#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    for(int i=0; i<n; i++){
        
        string temp;
        
        if(i % 2 == 0){
            
            temp = "수";
            answer += temp;
            
        }else{
            
            temp = "박";
            answer += temp;
        }
    }
    
    return answer;
}
