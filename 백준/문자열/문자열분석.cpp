#include <iostream>
#include <string> 

using namespace std;

int main(){
    
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    
    string str;
    
    while(getline(cin, str)){
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        
        int len = str.length();
        
        for(int j=0; j<len; j++){
            if(97<=str[j] && str[j]<=122){
                a += 1;
            }else if(65<=str[j] && str[j]<=90){
                b += 1;
            }else if(48<=str[j] && str[j]<=57){
                c += 1;
            }else if(str[j] == ' '){
                d += 1;
            }
        }
        
        cout << a << " " << b << " " << c << " " << d << '\n';
        
    }
    
    
    
    
}
