1. 문제 난이도(1~10) - 1이 최하, 10이 최상
- 3~4


2. 문제 유형
- DP
  
  
3. 혼자 해결했는지 여부
- O
  
  
4. 소요 시간
- 1시간

5. 문제 해결 과정

- DP 문제였고, 한 번 풀었던 문제인데, 규칙이 바로 떠올라서 적용해서 풀었다.
 
- 중간에 dp[i][0] = 1이라고 적어야 하는 부분을, dp[i][0] == 1로 적어서
  30분 정도 디버깅을 했다. 
-> 에러가 잘 안 보일 때는, 코드를 다시 한 번 꼼꼼히 살펴보면 좋을 듯 하다. 

- 문자는 아스키 코드 값으로 변환되므로, 그대로 == 로 비교할 수 있다. 


#include <iostream>
#include <string> 
#include <cstring> 
#include <algorithm> 

using namespace std;

int main(){
    
    string str1;
    string str2;
    cin >> str1 >> str2;
    
    int dp[1010][1010];
    
    memset(dp, 0, sizeof(dp));
    
    for(int i=0; i<str1.size(); i++){
        if(str2[0] == str1[i]){
            dp[0][i] = 1;
        }else{
            if(i == 0){
                dp[0][i] = 0; 
            }else{
                dp[0][i] = dp[0][i-1];
            }
        }
    }
    
    for(int i=0; i<str2.size(); i++){
        if(str1[0] == str2[i]){
            dp[i][0] = 1;
        }else{
            if(i == 0){
                dp[i][0] = 0;
            }else{
                dp[i][0] = dp[i-1][0];
            }
        }
    }
    
    
    for(int i=1; i<str2.size(); i++){
        for(int j=1; j<str1.size(); j++){
            if(str2[i] == str1[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout << dp[str2.size()-1][str1.size()-1];
      
    
    
}
