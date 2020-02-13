#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    
    int len = seoul.size();
    int index = 0; 
    
    for(int i=0; i<len; i++){
        if(seoul[i] == "Kim" ){
            index = i;
        }
    }
    
    answer += "김서방은 ";
    answer += to_string(index);
    answer += "에 있다";
    
    return answer;
}
