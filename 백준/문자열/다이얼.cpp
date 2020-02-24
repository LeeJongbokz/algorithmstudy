#include <iostream>

using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int len = s.length();
    int time = 0;
    
    for(int i=0; i<len; i++){
        
        if(65<=s[i] && s[i]<=67){
            time += 3;
        }else if(68<=s[i] && s[i]<=70){
            time += 4;
        }else if(71<=s[i] && s[i]<=73){
            time += 5;
        }else if(74<=s[i] && s[i]<=76){
            time += 6;
        }else if(77<=s[i] && s[i]<=79){
            time += 7;
        }else if(80<=s[i] && s[i]<=83){
            time += 8;
        }else if(84<=s[i] && s[i]<=86){
            time += 9;
        }else if(87<=s[i] && s[i]<=90){
            time += 10;
        }
    }
    
    cout << time; 
    
}
