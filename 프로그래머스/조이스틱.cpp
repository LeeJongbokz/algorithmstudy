#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int len = name.length();
    
    for(int i=0; i<len; i++){
        if(65<=name[i] && name[i]<=78){
            int num = name[i] - 65;
            answer += num;
        }else{
            int num = 91 - name[i];
            answer += num;
        }
    }
    
    int total = 0;
    
    for(int i=0; i<len; i++){
        if(name[i] != 'A'){
            total += 1;
        }
    }
    
    int smallest = 10000000; 
    
    for(int i=0; i<len; i++){
        
        int move = i;
        int num = 0; 
        
        for(int j=0; j<=i; j++){
            if(name[j] != 'A'){
                num += 1;
            }
        }
        
        int pos = i;
        
        while(1){
            pos -= 1;
            move += 1;
            
            if(pos < 0){
               pos = len-1;    
            }
            
            if(pos > i){
                if(name[pos] != 'A'){
                    num += 1;
                }
            }
            
            if(num == total){
                break;
            }
            
        }
        
        if(smallest > move){
           smallest = move;
        }
    }
    
    
    answer += smallest; 
       
    
    return answer;
    
    
}
