#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    bool num[1010] = {0};
    
    for(int i=100; i<=999; i++){
        int a = i / 100;
        int b = (i/10)%10;
        int c = i%10;
        
        if(a!=b && b!=c && c!=a && a!=0 && b!=0 && c!=0){
            num[i] = true;
        }
    }
    
    int len = baseball.size();
    
    for(int i=0; i<len; i++){
        int temp = baseball[i][0];
        
        int a = temp / 100;
        int b = (temp/10)%10;
        int c = temp % 10;
        
        int strike = baseball[i][1];
        int ball = baseball[i][2];
        
        for(int j=100; j<=999; j++){
            if(num[j] == false){
                continue;
            }
            
            int numa = j / 100;
            int numb = (j/10) % 10;
            int numc = j % 10;
            
            int numStrike = 0;
            int numBall = 0;
            
            if(a == numa){
                numStrike += 1;
            }
            if(b == numb){
                numStrike += 1;
            }
            if(c == numc){
                numStrike += 1;
            }
            
            if(a == numb || a == numc){
                numBall += 1;
            }
            if(b == numa || b == numc){
                numBall += 1;
            }
            if(c == numa || c == numb){
                numBall += 1;
            }
            
            if(strike == numStrike && ball == numBall){
                continue;
            }else{
                num[j] = false;
            }
            
        }
        
    } 
    
    for(int i=100; i<=999; i++){
        if(num[i] == true){
            answer += 1; 
        }
    }
        
    
    return answer;
}
