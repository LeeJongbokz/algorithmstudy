#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int len = s.length();
    
    int num1 = 0;
    int num2 = 0; 
    
    for(int i=0; i<len; i++){
        if(s[i] == 'p' || s[i] == 'P'){
            num1 += 1;
        }else if(s[i] == 'y' || s[i] == 'Y'){
            num2 += 1;
        }else{
            continue;
        }
    }
    
    if(num1 == num2){
        answer = true;
    }else{
        answer = false;
    }
    

    return answer;
}
