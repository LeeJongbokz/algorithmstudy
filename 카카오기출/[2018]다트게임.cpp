#include <string>
#include <algorithm>

using namespace std;

int solution(string dartResult) {
    
    int answer = 0; 
    
    int len = dartResult.length();
    
    int temp = 0; 
    
    for(int i=0; i<len; i++){
        if(dartResult[i] == '1' && dartResult[i+1]=='0'){
            dartResult[i]= ':';
            dartResult.erase(i+1,1);
        }
    }
    
    int dartlen = dartResult.length();
    
    for(int i=0; i<dartlen; i++){
        
        if(dartResult[i] == 'S'){
            answer += pow((dartResult[i-1]-48),1);
        }else if(dartResult[i] == 'D'){
            answer += pow((dartResult[i-1]-48),2);
        }else if(dartResult[i] == 'T'){
            answer += pow((dartResult[i-1]-48),3);
        }else if(dartResult[i] == '*'){
            
             if(dartResult[i-1] == 'S'){
                answer += pow((dartResult[i-2]-48),1);
             }else if(dartResult[i-1] == 'D'){
                answer += pow((dartResult[i-2]-48),2);
             }else if(dartResult[i-1] == 'T'){
                answer += pow((dartResult[i-2]-48),3);
             }
        
        
        if(i == 2){
            continue;
        }
        
        
        if(dartResult[i-3] == 'S'){
            answer += pow((dartResult[i-4]-48),1);
        }else if(dartResult[i-3] == 'D'){
            answer += pow((dartResult[i-4]-48),2);
        }else if(dartResult[i-3] == 'T'){
            answer += pow((dartResult[i-4]-48),3);
        }else if(dartResult[i-3] == '#'){
            answer -= temp;
        }else if (dartResult[i - 3] == '*') {
				if (dartResult[i - 4] == 'S') {
					answer += 2*pow((dartResult[i - 5] - 48), 1);
				}
				else if (dartResult[i - 4] == 'D') {
					answer += 2*pow((dartResult[i - 5] - 48), 2);
				}
				else if (dartResult[i - 4] == 'T') {
					answer += 2*pow((dartResult[i - 5] - 48), 3);
				}
		}
            
        }else if(dartResult[i] == '#'){
            
            if(dartResult[i-1]=='S'){
                answer -= 2*pow((dartResult[i-2]-48),1);
                temp = pow(dartResult[i-2]-48,1);
            }else if(dartResult[i-1]=='D'){
                answer -= 2*pow((dartResult[i-2]-48),2);
                temp = pow(dartResult[i-2]-48,2);
            }else if(dartResult[i-1]=='T'){
                answer -= 2*pow((dartResult[i-2]-48),3);
                temp = pow(dartResult[i-2]-48,3);
            }
            
        }
    }
    
    return answer;
    
    
}
