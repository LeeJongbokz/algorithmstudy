#include <iostream>
#include <string> 

using namespace std;

int main(){
    
    string s;
    getline(cin, s);
    
    int len = s.length();
    int cnt = 0; 
    
    for(int i=0; i<len; i++){
        if(i == 0){
            if(s[i] != ' '){
                cnt += 1;
            }
        }else{
            if(s[i-1] == ' ' && s[i] != ' '){
                cnt += 1;
            }
        }
    }
    
    cout << cnt;
    
}
