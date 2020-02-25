#include <iostream>

using namespace std;

int main(){
    
    int year = 1;
    
    int E,S,M;
    cin >> E >> S >> M;
    
    while(1){
   
        if((year-1) % 15 == (E-1) && (year-1) % 28 == (S-1) && (year-1) % 19 == (M-1)){
            break;
        }else{
            year++;
        }
           
    }
    
    cout << year; 
    
    
    
}
