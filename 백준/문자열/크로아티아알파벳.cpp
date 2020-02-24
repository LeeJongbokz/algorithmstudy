#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int len = s.length();
    int cnt = 0;
    
    for(int i=0; i<len; ){
        if(s[i] == 'c'){
            if(s[i+1] == '='){
                cnt += 1;
                i += 2;
            }else if(s[i+1] == '-'){
                cnt += 1;
                i += 2;
            }else{
                cnt += 1;
                i += 1;
            }
        }else if(s[i] == 'd'){
            if(s[i+1] == 'z' && s[i+2] == '='){
                cnt += 1;
                i += 3;
            }else if(s[i+1] == '-'){
                cnt += 1;
                i += 2;
            }else{
                cnt += 1;
                i += 1;
            }
        }else if(s[i] == 'l'){
            if(s[i+1] == 'j'){
                cnt += 1;
                i += 2;
            }else{
                cnt += 1;
                i += 1;
            }
        }else if(s[i] == 'n'){
            if(s[i+1] == 'j'){
                cnt += 1;
                i += 2;
            }else{
                cnt += 1;
                i += 1;
            }
        }else if(s[i] == 's'){
            if(s[i+1] == '='){
                cnt += 1;
                i += 2;
            }else{
                cnt += 1;
                i += 1;
            }
        }else if(s[i] == 'z'){
            if(s[i+1] == '='){
                cnt += 1;
                i += 2;
            }else{
                cnt += 1;
                i += 1;
            }
        }else{
            cnt += 1;
            i += 1;
        }
         
    }
    
    
    cout << cnt; 
    
    

    
}
