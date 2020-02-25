#include <iostream>
#include <string> 

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    string temp;
    int result = 0; 
    int len = str.length();
    bool minus = false;
    
    for(int i=0; i<=len; i++){
        
        if(str[i] == '+' || str[i] == '-' || str[i] =='\0'){
                  
            if(minus){
                result -= stoi(temp);
            }else{
                result += stoi(temp);
            }
            temp = "";
            
            if(str[i] == '-'){
                minus = true;
            }
            
        }else{
            temp += str[i];
        }
       
    }
    
    
    cout << result;
    
    
    
    
    
}
