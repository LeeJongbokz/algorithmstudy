#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

bool cmp(int a, int b){
    string aa = to_string(a);
    string bb = to_string(b);
    string tempA = aa+bb;
    string tempB = bb+aa;
    int numA = stoi(tempA);
    int numB = stoi(tempB);
    
    if(numA > numB){
        return true;
    }else{
        return false; 
    }    
    
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    for(int i=0; i<numbers.size(); i++){
        string temp = to_string(numbers[i]);
        answer += temp; 
    }
    
    bool isAllZero = true; 
    
    for(int i=0; i<answer.size(); i++){
        if(answer[i] != '0'){
            isAllZero = false;
            break;
        }
    }
    
    if(isAllZero == true){
        answer = '0';
    }
    
    return answer;
}
